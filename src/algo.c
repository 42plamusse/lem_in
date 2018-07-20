/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 18:06:35 by plamusse          #+#    #+#             */
/*   Updated: 2018/07/20 16:53:26 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		cur_way_cpy(t_hex *env)
{
	t_way	way;
	int		i;

	if (!(way.way = (int*)malloc(sizeof(int) * env->index_way)))
		return (MALLOC_ERROR);
	i = 0;
	while (i < env->index_way)
	{
		way.way[i] = env->cur_way[i];
		i++;
	}
	way.len = env->index_way;
	if (!(ft_lst2c_push_back(&(env->ways), ft_lstnew((t_way*)&way, sizeof(t_way)))))
		return (MALLOC_ERROR);
	env->nbr_ways++;
	return (SUCCESS);
}

t_vert	*get_vertices(t_hex *env, t_vert *edge)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = env->verts;
	while (i < env->nbr_vert)
	{
		if (((t_vert*)(tmp->content))->id == edge->id)
			return (((t_vert*)(tmp->content)));
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}
int		path_finding(t_hex *env, t_vert *cur_vert)
{
	t_vert	*edge;
	t_list	*tmp;
	int		ret;
	int		i;

	ret = SUCCESS;
	cur_vert->on = 1;
	tmp = cur_vert->edges;
	if (tmp)
		edge = ((t_vert*)(tmp->content));
	else
		edge = NULL;
	//ret = ERROR;
	ft_printf("cur id= %i\n", cur_vert->id);
	ft_printf("cur adress= %p\n", cur_vert);
	env->cur_way[env->index_way++] = cur_vert->id;
	i = 0;
	while (tmp && edge && ft_printf("i= %i\n", i) && i++ < cur_vert->nbr_edges && !edge->end)
	{
		ft_printf("edge id= %i\n", edge->id);
		ft_printf("edge adress= %p\n", edge);
		ft_printf("on= %i\n", edge->on);
		if (edge->on == 0 && edge->deadend != -1)
			ret = path_finding(env, get_vertices(env, edge));
		tmp = tmp->next;
		if (tmp)
			edge = ((t_vert*)(tmp->content));
		else
		{
			ft_printf("no tmp\n");
			edge = NULL;
		}
		ft_printf("end of lvl\n");
		// tmp ou edge font segfault
	}
	ft_printf("end= %i\n", edge->end);
	if (edge && edge->end)
	{
		if (cur_way_cpy(env) == MALLOC_ERROR)
			return (MALLOC_ERROR);
	}
	//cur_vert->deadend = ret;
	cur_vert->on = 0;
	env->cur_way[env->index_way--] = 0;
	return (ret);
}

t_vert	*get_start_vert(t_hex *env)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = env->verts;
	while (i < env->nbr_vert)
	{
		if (((t_vert*)(tmp->content))->start == 1)
			return (((t_vert*)(tmp->content)));
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}

int		set_int_tab_to_zero(t_hex *env)
{
	int	i;

	if (!(env->cur_way = (int*)malloc(sizeof(int) * (env->nbr_vert + 1))))
		return (MALLOC_ERROR);
	i = 0;
	while (i < env->nbr_vert)
		env->cur_way[i++] = 0;
	return (SUCCESS);
}

int		resolve_hex(t_hex *env)
{
	if (set_int_tab_to_zero(env) == MALLOC_ERROR)
		return (MALLOC_ERROR);
	path_finding(env, get_start_vert(env));
	ft_printf("sortie pathfinding\n");
	return (SUCCESS);
}

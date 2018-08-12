/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 18:06:35 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/12 16:25:00 by plamusse         ###   ########.fr       */
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
	env->cur_way[env->index_way++] = cur_vert->id;
	i = 0;
	while (i++ < cur_vert->nbr_edges && !edge->end)
	{
		if (edge->on == 0)
			ret = path_finding(env, edge);
		tmp = tmp->next;
		if (tmp)
			edge = ((t_vert*)(tmp->content));
		else
			edge = NULL;
	}
	if (edge && edge->end)
	{
		env->cur_way[env->index_way++] = 1;
		if (cur_way_cpy(env) == MALLOC_ERROR)
			return (MALLOC_ERROR);
		env->cur_way[env->index_way--] = 0;
	}
	cur_vert->on = 0;
	env->cur_way[env->index_way--] = 0;
	return (ret);
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

void	swap_elem(t_list *a)
{
	t_list	*first;
	t_list	*second;

	first = a;
	second = first->next;
	first->prev->next = second;
	second->prev = first->prev;
	second->next->prev = first;
	first->next = second->next;
	first->prev = second;
	second->next = first;
}

void	sort_list_ways(t_hex *env)
{
	t_list	*tmp;
	int	i;
	int	j;
	int	cur;
	int	next;

	tmp = env->ways;
	i = env->nbr_ways;
	while (i > 1)
	{
		j = 0;
		while (j < env->nbr_ways)
		{
			cur = ((t_way*)(tmp->content))->len;
			next = ((t_way*)(tmp->next->content))->len;
			if (cur > next && j < i - 1)
			{
				swap_elem(tmp);
			}
			else
				tmp = tmp->next;
			j++;
		}
		env->ways = tmp;
		i--;
	}	
}

int		resolve_hex(t_hex *env)
{
	t_vert	*start;

	if (set_int_tab_to_zero(env) == MALLOC_ERROR)
		return (MALLOC_ERROR);
	start = get_vert_from_id(env, 0);
	if (start)
	{
		path_finding(env, start); 
		if (env->ways)
		{
			sort_list_ways(env);
			ft_printf("\n");
			print_ants(env);
		}
	}
	return (SUCCESS);
}

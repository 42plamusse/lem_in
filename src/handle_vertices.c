/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_vertices.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:01:16 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/12 17:11:54 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		init_vert(t_hex *env, t_vert *vert, char **tab)
{
	vert->name = ft_strdup(tab[0]);
	if (env->start == 1)
	{
		vert->start = 1;
		env->start = -1;
		vert->id = 0;
	}
	else
		vert->start = 0;
	if (env->end == 1 && env->start != 1)
	{
		vert->end = 1;
		env->end = -1;
		vert->id = 1;
	}
	else
		vert->end = 0;
	if (vert->start == 0 && vert->end == 0)
		vert->id = env->global_id++;
	vert->edges = NULL;
	vert->nbr_edges = 0;
	vert->ant = 0;
	vert->on = 0;
}

int			parse_vertices(char **tab)
{
	int			ret;

	ret = SUCCESS;
	if (ft_tablen(tab) == 3)
	{
		if (parse_int(tab[1]) == ERROR || parse_int(tab[2]) == ERROR)
			ret = ERROR;
		if (ft_strchr(tab[0], '-'))
			ret = ERROR;
	}
	else
		ret = ERROR;
	return (ret);
}

int			handle_vertices(t_hex *env, char *line)
{
	t_vert		vert;
	int			ret;
	char		**tab;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		return (MALLOC_ERROR);
	ret = SUCCESS;
	if ((ret = parse_vertices(tab)) == SUCCESS)
	{
		ft_printf("%s\n", line);
		init_vert(env, &vert, tab);
		if (ft_lst2c_push_back(&(env->verts), ft_lstnew(&vert, sizeof(vert)))
				== NULL)
		{
			free(vert.name);
			ret = MALLOC_ERROR;
		}
		else
			env->nbr_vert++;
	}
	ft_tabclr(tab);
	return (ret);
}

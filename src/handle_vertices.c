/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_verticals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:01:16 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/25 17:05:49 by plamusse         ###   ########.fr       */
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
	}
	else
		vert->start = 0;
	if (env->end == 1)
	{
		vert->end = 1;
		env->end = -1;
	}
	else
		vert->end = 0;
	vert->edges = NULL;
}
int			parse_vertices(char **tab)
{
	if (ft_tablen(tab) == 3)
	{
		if (parse_int(tab[1]) == SUCCESS && parse_int(tab[2]) == SUCCESS)
			return (SUCCESS);
	}
	return (ERROR);
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

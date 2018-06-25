/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_edges.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:13:50 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/25 19:00:03 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		check_existing_edge(t_vert *vert1, t_vert *vert2)
{
	t_list	*tmp;
	int		i;

	if (!(tmp = vert1->edges))
		return (ERROR);
	i = 0;
	while (i < vert1->nbr_edge)
	{
		if (((t_vert*)(tmp->content)) == vert2)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i == vert1->nbr_edge)
		return (ERROR);
	else
		return (SUCCESS);
}

t_vert	*get_vert_from_name(t_hex *env, char *str)
{
	t_list	*tmp;
	char	*name;
	int		i;

	i = 0;
	tmp = env->verts;
	while (i < env->nbr_vert)
	{
		name = ((t_vert*)(tmp->content))->name;
		if (!ft_strcmp(str, name))
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i != env->nbr_vert)
		return ((t_vert*)(tmp->content));
	else
		return (NULL);
}

int		handle_edges(t_hex *env, char *line)
{
	t_vert		*vert1;
	t_vert		*vert2;
	char		**tab;
	int			ret;

	if (ft_countchar(line, '-') != 1)
		return (ERROR);
	if ((tab = ft_strsplit(line, '-')) == NULL)
		return (MALLOC_ERROR);
	env->step = 2;
	ret = SUCCESS;
	vert1 = get_vert_from_name(env, tab[0]);
	vert2 = get_vert_from_name(env, tab[1]);
	if (vert1 && vert2)
	{
		if (check_existing_edge(vert1, vert2) == ERROR);
		ft_printf("%s\n", line);
	}
	return (ret);
}

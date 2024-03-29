/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_edges.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:13:50 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/15 12:41:25 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		check_existing_edge(t_vert *vert1, t_vert *vert2)
{
	t_list	*tmp;
	int		i;

	if (!(tmp = vert1->edges))
		return (SUCCESS);
	i = 0;
	while (i < vert1->nbr_edges)
	{
		if (((t_vert*)(tmp->content)) == vert2)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i == vert1->nbr_edges)
		return (SUCCESS);
	else
		return (ERROR);
}

static t_vert	*get_vert_from_name(t_hex *env, char *str)
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

static int		create_edge(t_vert *vert1, t_vert *vert2)
{
	if (ft_lst_push_front(&(vert1->edges), ft_lstnew(&vert2, sizeof(t_vert*)))
			== NULL)
		return (MALLOC_ERROR);
	if (ft_lst_push_front(&(vert2->edges), ft_lstnew(&vert1, sizeof(t_vert*)))
			== NULL)
		return (MALLOC_ERROR);
	free(vert1->edges->content);
	free(vert2->edges->content);
	vert1->edges->content = vert2;
	vert2->edges->content = vert1;
	vert1->nbr_edges++;
	vert2->nbr_edges++;
	return (SUCCESS);
}

static int		check_and_create(t_vert *vert1, t_vert *vert2, char *line)
{
	int	ret;

	if (vert1 && vert2 && vert1 != vert2)
	{
		if (check_existing_edge(vert1, vert2) != ERROR)
		{
			if (!(ret = create_edge(vert1, vert2)))
				ft_printf("%s\n", line);
		}
		else
			ret = ERROR;
	}
	else
		ret = ERROR;
	return (ret);
}

int				handle_edges(t_hex *env, char *line)
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
	ft_tabclr(tab);
	ret = check_and_create(vert1, vert2, line);
	return (ret);
}

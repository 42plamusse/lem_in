/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:00:18 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/14 18:39:28 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_hex(t_hex *env)
{
	t_list	*verts;
	t_list	*edges;
	int		i;
	int		j;

	verts = env->verts;
	i = 0;
	write(1, "\n", 1);
	while (i < env->nbr_vert)
	{
		ft_printf("vert= %s\n", ((t_vert*)(verts->content))->name);
		edges = ((t_vert *)(verts->content))->edges;
		j = 0;
		while (j < ((t_vert *)(verts->content))->nbr_edges)
		{
			ft_printf("%s-%s\n",
					((t_vert*)(verts->content))->name,
					((t_vert*)(edges->content))->name);
			j++;
			edges = edges->next;
		}
		i++;
		verts = verts->next;
		write(1, "\n", 1);
	}
}

void	print_ways(t_hex *env)
{
	t_list	*tmp;
	int		*tab;
	int		i;
	int		j;

	tmp = env->ways;
	i = 0;
	while (tmp && i < env->nbr_ways)
	{
		ft_printf("len= %i\n", ((t_way*)(tmp->content))->len);
		tab = ((t_way*)(tmp->content))->way;
		j = 0;
		while (j < ((t_way*)(tmp->content))->len)
		{
			ft_printf("%d", tab[j]);
			j++;
			if (j < ((t_way*)(tmp->content))->len)
				ft_printf("-");
		}
		write(1, "\n", 1);
		i++;
		tmp = tmp->next;
	}
}

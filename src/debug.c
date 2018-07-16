/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:00:18 by plamusse          #+#    #+#             */
/*   Updated: 2018/07/16 18:01:22 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	print_hex(t_hex *env)
{
	t_list *verts;
	t_list *edges;
	int		i;
	int		j;

	verts = env->verts;
	i = 0;
	while (i < env->nbr_vert)
	{
		ft_printf("vert= %s\n", ((t_vert*)(verts->content))->name);
		edges = ((t_vert *)(verts->content))->edges;
		j = 0;
		while (j < ((t_vert *)(verts->content))->nbr_edges)
		{
			ft_printf("edges= %s\n", ((t_vert*)(edges->content))->name);
			j++;
			edges = edges->next;
		}
		i++;
		verts = verts->next;
	}
}

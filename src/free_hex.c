/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:59:28 by plamusse          #+#    #+#             */
/*   Updated: 2018/07/19 13:46:34 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	free_hex(t_hex *env)
{
	t_list *verts;
	t_list *edges;
	int		i;

	if (env->cur_way)
		free(env->cur_way);
	verts = env->verts;
	i = 0;
	while (i < env->nbr_vert)
	{
		free(((t_vert*)(verts->content))->name);
		edges = ((t_vert *)(verts->content))->edges;
		ft_lst2c_del(&(edges), &ft_lst_memclr);
		i++;
		verts = verts->next;
	}
	ft_lst2c_del(&(verts), &ft_lst_memclr);
}

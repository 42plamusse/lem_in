/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:59:28 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/12 15:46:58 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	free_verts(t_hex *env)
{
	t_list *verts;
	t_list *edges;
	t_list	*tmp;
	int		i;

	verts = env->verts;
	i = 0;
	while (i < env->nbr_vert)
	{
		edges = ((t_vert*)(verts->content))->edges;
		while (edges)
		{
			tmp = edges;
			edges = edges->next;
			free(tmp);
		}
		ft_strdel(&((t_vert*)(verts->content))->name);	
		verts = verts->next;
		i++;
	}
	ft_lst2c_del(&(verts), &ft_lst_memclr);
}

static void	free_ways(t_hex *env)
{
	t_list *ways;
	int		i;

	if (env->cur_way)
		free(env->cur_way);
	ways = env->ways;
	i = 0;
	while (i < env->nbr_ways)
	{
		free(((t_way*)(ways->content))->way);
		i++;
		ways = ways->next;
	}
	ft_lst2c_del(&(ways), &ft_lst_memclr);
}

void	free_hex(t_hex *env)
{
	free_verts(env);
	free_ways(env);
}

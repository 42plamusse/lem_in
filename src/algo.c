/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 18:06:35 by plamusse          #+#    #+#             */
/*   Updated: 2018/07/18 18:53:01 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		path_finding(t_hex *env, t_vert *cur_vert)
{
	t_vert	*edge;
	int		ret;

	cur_vert->on = 1;
	edge = cur_vert->edges;
	if (edge)
		ret = SUCCESS;
	else
		ret = ERROR;
	while (edge && !edge->end)
	{
	}
	cur_vert->on = 0;
	return (ret);
}

int			resolve_hex(t_hex *env)
{
	if (!(env->cur_way = (int*)malloc(sizeof(int) * env->nbr_vert)))
		return (MALLOC_ERROR);
	path_finding(env, get_start_edge(env));
}

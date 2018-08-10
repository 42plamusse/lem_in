/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:38:19 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/10 14:38:55 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_vert	*get_vert_from_id(t_hex *env, int id)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = env->verts;
	while (i < env->nbr_vert)
	{
		if (((t_vert*)(tmp->content))->id == id)
			return (((t_vert*)(tmp->content)));
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}

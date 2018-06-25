/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:59:28 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/25 17:16:01 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	free_hex(t_hex *env)
{
	t_list	*tmp;
	int		i;

	tmp = env->verts;
	i = 0;
	while (i < env->nbr_vert)
	{
		free(((t_vert*)tmp->content)->name);
		tmp = tmp->next;
		i++;
	}
	ft_lst2c_del(&(env->verts), &ft_lst_memclr);
}

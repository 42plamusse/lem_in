/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:46:24 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/15 12:59:13 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_hex(t_hex *env)
{
	if (env->ants <= 0 || env->nbr_vert == 0 || env->start == 0 || env->end == 0)
		return (ERROR);
	return (SUCCESS);
}
static void	init_hex(t_hex *env)
{
	env->ants = INIT_ZERO;
	env->step = INIT_ZERO;
	env->start = INIT_ZERO;
	env->end = INIT_ZERO;
	env->verts = NULL;
	env->nbr_vert = 0;
	env->ways = NULL;
	env->cur_way = NULL;
	env->index_way = 0;
	env->nbr_ways = 0;
	env->global_id = 2;
}

int			main(void)
{
	t_hex	env;

	init_hex(&env);
	if (parse_hex(&env) == SUCCESS && check_hex(&env) == SUCCESS)
	{
		if (resolve_hex(&env) != SUCCESS)
			ft_printf("ERROR\n");
	}
	else
		ft_printf("ERROR\n");
	free_hex(&env);
	return (0);
}

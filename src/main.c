/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:46:24 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/23 17:28:02 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		parse_hex(t_hex *env)
{
	char	*line = NULL;
	int		ret;

	ret = SUCCESS;
	(void)env;
	while (ret != ERROR && get_next_line(STDIN_FILENO, &line) > END_OF_FILE)
	{
		if (*line == '#')
		{
			if (*(line + 1) == '#')
				ret = SUCCESS; //handle_command(env, line);
			else
				ft_printf("%s\n", line);
		}
		//else if (*line == 'L')
		//	ret == ERROR;
		free(line);
	}
	return (ret);
}

void	init_hex(t_hex *env)
{
	env->ants = INIT_ZERO;
	env->step = INIT_ZERO; 
}

int		main(void)
{
	t_hex	env;

	init_hex(&env);
	parse_hex(&env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:46:24 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/25 19:00:06 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		handle_ants(t_hex *env, char *line)
{
	if (parse_int(line) == SUCCESS)
	{
		env->ants = ft_atoi(line);
		ft_printf("%i\n", env->ants);
		env->step = 1;
		return (SUCCESS);
	}
	return (ERROR);
}

int		handle_command(t_hex *env, char *line)
{
	if (!ft_strcmp(line, "##start"))
	{
		if (env->start == 0)
			env->start = 1;
		else
			return (ERROR);
	}
	else if (!ft_strcmp(line, "##end"))
	{
		if (env->end == 0)
			env->end = 1;
		else
			return (ERROR);
	}
	return (SUCCESS);
}

int		parse_hex(t_hex *env)
{
	char	*line = NULL;
	int		ret;

	ft_printf("ok\n");
	ret = SUCCESS;
	while (ret > ERROR && get_next_line(STDIN_FILENO, &line) > END_OF_FILE)
	{
		if (*line == '#')
		{
			if (*(line + 1) == '#')
			{
				ft_printf("%s\n", line);
				if (env->step == 1)
					ret = handle_command(env, line);
				else
					ret = ERROR;
			}
			else
				ft_printf("%s\n", line);
		}
		else if (*line == 'L')
			ret = ERROR;
		else if (env->step == 0)
			ret = handle_ants(env, line);
		else if (env->step == 1 && ft_countchar(line, ' ') == 2)
			ret = handle_vertices(env, line);
		else if (ft_countchar(line, ' ') == 0)
			ret = handle_edges(env, line);
		else
			ret = ERROR;
		//ft_printf("ret= %d\n", ret);
		free(line);
	}
	return (ret);
}

void	init_hex(t_hex *env)
{
	env->ants = INIT_ZERO;
	env->step = INIT_ZERO; 
	env->start = INIT_ZERO;
	env->end = INIT_ZERO; 
	env->verts = NULL;
	env->nbr_vert = 0;
}

int		main(void)
{
	t_hex	env;

	init_hex(&env);
	parse_hex(&env);
	free_hex(&env);
	return (0);
}

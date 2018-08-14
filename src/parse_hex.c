/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:53:30 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/14 18:38:34 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		handle_ants(t_hex *env, char *line)
{
	if (parse_int(line) == SUCCESS)
	{
		env->ants = ft_atoi(line);
		if (env->ants > 0)
		{
			ft_printf("%i\n", env->ants);
			env->step = 1;
			return (SUCCESS);
		}
	}
	return (ERROR);
}

static int		handle_commands(t_hex *env, char *line)
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
	ft_printf("%s\n", line);
	return (SUCCESS);
}

static int		handle_comments(t_hex *env, char *line)
{
	int		ret;

	ret = SUCCESS;
	if (*(line + 1) == '#')
	{
		if (env->step == 1)
			ret = handle_commands(env, line);
		else
			ret = ERROR;
	}
	else
		ft_printf("%s\n", line);
	return (ret);
}

int				parse_hex(t_hex *env)
{
	char	*line;
	int		ret;

	ret = SUCCESS;
	while (ret > ERROR && get_next_line(STDIN_FILENO, &line) > END_OF_FILE)
	{
		if (*line == '#')
			ret = handle_comments(env, line);
		else if (*line == 'L')
			ret = ERROR;
		else if (env->step == 0)
			ret = handle_ants(env, line);
		else if (env->step == 1 && ft_countchar(line, ' ') >= 2)
			ret = handle_vertices(env, line);
		else if (ft_countchar(line, ' ') == 0)
			ret = handle_edges(env, line);
		else
			ret = ERROR;
		free(line);
	}
	return (ret);
}

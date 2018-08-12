/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 17:53:30 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/12 17:54:19 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
****** INCLUDE ******
*/

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

/*
****** DEFINE ******
*/

# define INIT_ZERO		0
# define END_OF_FILE	0
# define SUCCESS		0
# define ERROR			-1
# define MALLOC_ERROR	-2

/*
****** STRUCT ******
*/

typedef struct	s_vert
{
	char	*name;
	int		id;
	int		on;
	int		deadend;
	int		nbr_edges;
	int		start;
	int		end;
	t_list	*edges;
	int		ant;
}				t_vert;

typedef	struct	s_way
{
	int	len;
	int	*way;
}				t_way;

typedef struct	s_hex
{
	t_list	*verts;
	int		ants;
	int		nbr_vert;
	int		step;
	int		start;
	int		end;
	int		global_id;
	t_list	*ways;
	int		*cur_way;
	int		index_way;
	int		nbr_ways;
}				t_hex;

/*
******	PARSING	*******
*/

int				parse_hex(t_hex *env);
int				handle_vertices(t_hex *env, char *line);
t_vert			*get_vert_from_id(t_hex *env, int id);
int				handle_edges(t_hex *env, char *line);

/*
*****		ALGO.C			*******
*/

int				resolve_hex(t_hex *env);
int				get_best_ways(t_hex *env);
void			print_ants(t_hex *env);

/*
******		FREE_HEX.C		*******
*/

void			free_hex(t_hex *env);

/*
*****		DEBUG.C			*******
*/

void			print_hex(t_hex *env);
void			print_ways(t_hex *env);

#endif

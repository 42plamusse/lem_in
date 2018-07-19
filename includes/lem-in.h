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
}				t_vert;

typedef struct	s_hex
{
	t_list	*verts;
	int		ants;
	int		nbr_vert;
	int		step;
	int		start;
	int		end;
	int		*cur_way;
	int		index_way;
	int		nbr_ways;
	t_list	*ways;
}				t_hex;

typedef	struct	s_way
{
	int	len;
	int	*way;
}				t_way;

/*
******	HANDLE_VERTICES.C	*******
*/

int			handle_vertices(t_hex *env, char *line);

/*
******	HANDLE_VERTICES.C	*******
*/

int			handle_edges(t_hex *env, char *line);
/*
******		FREE_HEX.C		*******
*/

void		free_hex(t_hex *env);

/*
*****		DEBUG.C			*******
*/

void		print_hex(t_hex *env);
void		print_ways(t_hex *env);

/*
*****		ALGO.C			*******
*/

int		resolve_hex(t_hex *env);

#endif

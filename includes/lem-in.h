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

/*
****** STRUCT ******
*/

typedef struct	s_hex
{
	int	ants;
	int	step;
}				t_hex;

#endif

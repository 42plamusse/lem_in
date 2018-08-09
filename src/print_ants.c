#include "lem-in.h"

static void	shift_ants(t_hex *env, t_way *way)
{
	t_list	*tmp;
	int	i;
	int	id;

	tmp = env->verts;
	ft_printf("i= %i\n", tmp);
	i = way->len - 1;
	while (i > 0)
	{
		id = way->way[i];
		ft_printf("%i\n", id);
		i--;
	}
}

void	print_ants(t_hex *env)
{
	t_way	*way;
	int	ants;

	way = ((t_way*)(env->ways->content));
	ants = 1;
	while (ants <= env->ants)
	{
		shift_ants(env, way);
		ants++;
	}
}

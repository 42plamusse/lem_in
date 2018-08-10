#include "lem-in.h"

static int	check_way_empty(t_hex *env, t_way *way, int len)
{
	int		i;
	t_vert	*cur;
	int		empty;

	i = 0;
	empty = 1;
	while (i < len)
	{
		cur = get_vert_from_id(env, way->way[i]);
		if (cur->ant)
			empty = 0;
		i++;
	}
	return (empty);
}

static void	shift_ants(t_hex *env, t_way *way)
{
	t_vert	*cur;
	t_vert	*prev;
	int	i;

	i = way->len - 1;
	while (i)
	{
		cur = get_vert_from_id(env, way->way[i]);
		//ft_printf("cur id= %i\n", cur->id);
		prev = get_vert_from_id(env, way->way[i - 1]);
		cur->ant = prev->ant;
		i--;
		if (cur->ant)
		{
			ft_printf("L%i-%s", cur->ant, cur->name);
			if (!check_way_empty(env, way, i))
				write(1, " ", 1);
		}
	}
	if (!check_way_empty(env, way, way->len))
		write(1, "\n", 1);
}

void	print_ants(t_hex *env)
{
	t_way	*way;
	t_vert	*start;
	int	ants;

	way = ((t_way*)(env->ways->content));
	ants = 1;
	start = get_vert_from_id(env, 0);
	while (ants <= env->ants)
	{
		start->ant = ants;
		shift_ants(env, way);
		ants++;
	}
	start->ant = 0;
	while (!check_way_empty(env, way, way->len))
		shift_ants(env, way);
}

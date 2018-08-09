#include "lem-in.h"


void	get_max_multipath(t_hex *env)
{
	t_list	*tmp;
	int	max;

	tmp = env->verts;
	max = 0;
	while (!(((t_vert*)(tmp->content))->start))
		tmp = tmp->next;
	max = ((t_vert*)(tmp->content))->nbr_edges;
	while (!(((t_vert*)(tmp->content))->end))
		tmp = tmp->next;
	if (max > ((t_vert*)(tmp->content))->nbr_edges)
		max = ((t_vert*)(tmp->content))->nbr_edges;
	env->max_multipath = max;
}

int	get_best_ways(t_hex *env)
{
	t_list	*tmpi;
	t_list	*tmpj;
	int	i;

	ft_printf("\n");
	print_ways(env);
	get_max_multipath(env);
		{
		}
		
	}
	return (SUCCESS);
}

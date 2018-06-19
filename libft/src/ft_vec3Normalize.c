/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3Normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:12:47 by plamusse          #+#    #+#             */
/*   Updated: 2018/03/11 18:58:00 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec			ft_vec3Normalize(t_vec v)
{
	t_vec	tmp;
	double	normal;
	double	div;

	div = sqrt(ft_vec3Dot(v, v));
	if (div != 0)
		normal = 1 / div;
	else
		normal = 0;
	tmp.x = v.x * normal;
	tmp.y = v.y * normal;
	tmp.z = v.z * normal;
	return (tmp);
}

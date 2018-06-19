/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3Scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:13:51 by plamusse          #+#    #+#             */
/*   Updated: 2018/03/11 19:16:06 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec		ft_vec3Scale(t_vec v, double scale)
{
	t_vec	tmp;

	tmp.x = v.x * scale;
	tmp.y = v.y * scale;
	tmp.z = v.z * scale;
	return (tmp);
}

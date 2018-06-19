/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:10:54 by plamusse          #+#    #+#             */
/*   Updated: 2018/03/09 14:29:34 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double		compute_decimal(char *str, double ret, int i)
{
	int				j;

	j = i;
	while (str[i] && ft_isdigit((int)str[i]))
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	if (j < i)
		ret = ret / powl(10, i - j);
	return (ret);
}

double		ft_atof(char *str)
{
	int			i;
	double		ret;
	int			sign;

	i = 0;
	ret = 0;
	while (str[i] && ft_isspace((int)str[i]))
		i++;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit((int)str[i]))
		ret = ret * 10 + (str[i++] - '0');
	if (str[i] == '.')
		ret = compute_decimal(str, ret, ++i);
	return (ret * sign);
}

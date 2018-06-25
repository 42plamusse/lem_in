/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:22:47 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/25 16:27:03 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		parse_int(char *elem)
{
	long long	tmp;
	int			i;
	int			sign;

	if (ft_strlen(elem) > 11)
		return (-1);
	i = 0;
	sign = 1;
	if (elem[i] == '-')
	{
		sign = -1;
		i++;
	}
	tmp = 0;
	while (elem[i] && ft_isdigit(elem[i]))
		tmp = tmp * 10 + (elem[i++] - '0');
	if (elem[i] || (tmp > 2147483647 && sign > 0) ||
					(tmp > 2147483648 && sign < 0))
		return (-1);
	return (0);
}

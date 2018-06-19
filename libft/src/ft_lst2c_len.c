/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2c_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:42:44 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/25 18:50:40 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst2c_len(t_list *lst)
{
	int		len;
	t_list	*tmp;

	tmp = lst;
	if (!lst)
		return (0);
	len = 1;
	tmp = lst;
	while (tmp->next != lst)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2c_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 21:05:30 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/25 17:12:39 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst2c_push_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return (NULL);
	if (!*alst)
	{
		new->prev = new;
		new->next = new;
		*alst = new;
		return (new);
	}
	tmp = *alst;
	new->next = tmp;
	new->prev = tmp->prev;
	tmp->prev->next = new;
	tmp->prev = new;
	if (tmp->next == tmp)
		tmp->next = new;
	return (new);
}

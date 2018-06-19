/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:49:30 by plamusse          #+#    #+#             */
/*   Updated: 2018/03/01 16:18:53 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_push_front(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return (NULL);
	if (*alst == NULL)
	{
		*alst = new;
		return (new);
	}
	tmp = *alst;
	new->next = tmp;
	*alst = new;
	return (new);
}

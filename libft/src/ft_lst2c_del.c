/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2c_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:26:31 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/25 18:54:26 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst2c_del(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;
	t_list	*tmp;
	int		len;
	int		i;

	if (!*alst)
		return ;
	elem = *alst;
	len = ft_lst2c_len(*alst) - 1;
	i = 0;
	while (i < len)
	{
		tmp = elem;
		del(elem->content, elem->content_size);
		elem->content_size = 0;
		elem = elem->next;
		free(tmp);
		i++;
	}
	del(elem->content, elem->content_size);
	elem->content_size = 0;
	free(elem);
	*alst = NULL;
}

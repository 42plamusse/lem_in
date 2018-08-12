/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_memclr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:45:40 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/12 14:15:21 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_lst_memclr(void *content, size_t content_size)
{
	(void)content_size;
	if (!content)
		return ;
	ft_bzero(content, content_size);
	free(content);
}

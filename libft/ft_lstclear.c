/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:42:45 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/27 01:42:45 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = *lst;
	while (b)
	{
		if (b->next)
			a = b->next;
		else
			a = NULL;
		ft_lstdelone(b, del);
		b = a;
	}
	(*lst) = NULL;
}

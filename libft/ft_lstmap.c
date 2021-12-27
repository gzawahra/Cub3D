/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:44:12 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/27 01:47:09 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	tmp = ft_lstnew(f(lst->content));
	new = tmp;
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = ft_lstnew(f(lst->content));
		if (!tmp->next)
		{
			ft_lstdelone(tmp->next, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (new);
}

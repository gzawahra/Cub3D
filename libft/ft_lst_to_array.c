/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 05:49:11 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/24 05:49:14 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**list_to_array(t_list *lst, int size)
{
	char	**array;
	int		i;
	t_list	*temp;

	i = 0;
	if (lst == NULL)
		return (NULL);
	array = (char**)malloc(sizeof(char*) * size + 1);
	temp = lst;
	while (temp)
	{
		array[i] = ft_strdup(temp->content);
		temp = temp->next;
		i++;
	}
	return (array);
}

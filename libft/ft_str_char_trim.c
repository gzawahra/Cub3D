/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_char_trim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 02:08:18 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/27 02:08:18 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_char_trim(char const *s, char c)
{
	int		i;
	int		j;
	char	*trim;

	i = 0;
	j = 0;
	while (s[i++])
		if (s[i] != c)
			j++;
	trim = (char *)malloc(sizeof(char) * (j + 1));
	if (!trim)
		return (trim);
	trim[j] = 0;
	i = 0;
	j = 0;
	while (s[i++])
	{
		if (s[i] != c)
			trim[j++] = s[i];
	}
	return (trim);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_leaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 05:50:45 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/24 05:50:46 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	free_sprites(t_sprite *sprite)
{
	t_sprite *tmp;

	tmp = sprite;
	if (tmp && tmp->next)
		free_sprites(tmp->next);
	free(tmp);
}

void	free_map(t_params *par)
{
	int i;

	i = 0;
	while (i < par->m_size)
	{
		free(par->map_tab[i]);
		i++;
	}
	free(par->map_tab);
}

void	free_map_list(t_list *map)
{
	t_list	*tmp;

	tmp = map;
	if (tmp && tmp->next)
		free_map_list(tmp->next);
	free(tmp->content);
	free(tmp);
}

void	free_text(t_text *text)
{
	if (text)
	{
		if (text->path)
			free(text->path);
		free(text);
	}
}

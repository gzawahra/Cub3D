/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 05:51:45 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/24 05:51:47 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

t_position		*ft_set_position(int x, int y, char dir)
{
	t_position	*posi;

	if (!(posi = malloc(sizeof(t_position) * 1)))
		return (NULL);
	posi->x = x;
	posi->y = y;
	posi->dir = dir;
	return (posi);
}

t_text			*ft_init_text(void)
{
	t_text		*texture;

	if (!(texture = malloc(sizeof(t_text) * 1)))
		return (NULL);
	texture->path = NULL;
	texture->w = 0;
	texture->h = 0;
	texture->text_img = NULL;
	texture->text_id = NULL;
	texture->bpp = 0;
	texture->size = 0;
	texture->endian = 0;
	return (texture);
}

t_sprite		*ft_new_spr_pos(int x, int y)
{
	t_sprite	*new;

	if (!(new = malloc(sizeof(t_sprite))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new);
}

void			ft_get_spr_pos(t_sprite **begin, int x, int y)
{
	t_sprite	*tmp;

	if (*begin)
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_new_spr_pos(x, y);
	}
	else
		*begin = ft_new_spr_pos(x, y);
}

void			ft_init_params(t_params *par)
{
	par->res_w = 0;
	par->res_w = 0;
	par->no_text = NULL;
	par->so_text = NULL;
	par->we_text = NULL;
	par->ea_text = NULL;
	par->sprit_text = NULL;
	par->fl_color = NULL;
	par->ceil_color = NULL;
	par->start = 0;
	par->map = NULL;
	par->m_size = 0;
	par->player_pos = NULL;
	par->sprite = NULL;
	par->ps = NULL;
	par->map_start = 0;
	par->map_tab = NULL;
	par->mlx_id = NULL;
	par->window_id = NULL;
	par->img_id = NULL;
	par->ray = NULL;
	par->key = NULL;
}

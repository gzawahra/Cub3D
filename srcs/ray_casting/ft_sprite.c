/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 05:53:32 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/24 05:53:34 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

double		sprite_distance(t_sprite *sprite, t_params *par)
{
	double	ret;

	ret = ((par->ray->start_posx - sprite->x) *
			(par->ray->start_posx - sprite->x) +
			(par->ray->start_posy - sprite->y) *
			(par->ray->start_posy - sprite->y));
	return (ret);
}

void		sort_sprites(t_sprite *lst, t_params *par)
{
	t_sprite	*tmp;
	int			tmpx;
	int			tmpy;

	tmp = lst;
	while (tmp && tmp->next)
	{
		if (sprite_distance(tmp, par) < sprite_distance(tmp->next, par))
		{
			tmpx = tmp->x;
			tmpy = tmp->y;
			tmp->x = tmp->next->x;
			tmp->y = tmp->next->y;
			tmp->next->x = tmpx;
			tmp->next->y = tmpy;
			tmp = lst;
		}
		else
			tmp = tmp->next;
	}
}

void		sprite_loop(t_params *par, t_ray *ray, t_ps *ps)
{
	int			i;
	int			y;
	int			d;

	i = ps->drawstart_x;
	while (i < ps->drawend_x)
	{
		ps->tex_x = (int)(256 * (i - (-ps->spritewidth / 2 +
			ps->spritescreen_x)) * par->sprit_text->w / ps->spritewidth) / 256;
		if (ps->transform_y > 0 && i > 0 && i < par->res_w &&
				ps->transform_y < ray->zbuffer[i])
		{
			y = ps->drawstart_y;
			while (y < ps->drawend_y)
			{
				d = (y) * 256 - par->res_h * 128 + ps->spriteheight * 128;
				ps->tex_y = ((d * par->sprit_text->h) / ps->spriteheight) / 256;
				ps->color = ft_get_pixel(par->sprit_text, ps->tex_x, ps->tex_y);
				if ((ps->color & 0x00ffffff) != 0)
					ft_frame_pixel(par, i, y, ps->color);
				y++;
			}
		}
		i++;
	}
}

void		draw_limit(t_params *par, t_ps *ps)
{
	ps->drawstart_y = -ps->spriteheight / 2 + par->res_h / 2;
	if (ps->drawstart_y < 0)
		ps->drawstart_y = 0;
	ps->drawend_y = ps->spriteheight / 2 + par->res_h / 2;
	if (ps->drawend_y >= par->res_h)
		ps->drawend_y = par->res_h - 1;
	ps->spritewidth = abs((int)(par->res_h / (ps->transform_y)));
	ps->drawstart_x = -ps->spritewidth / 2 + ps->spritescreen_x;
	if (ps->drawstart_x < 0)
		ps->drawstart_x = 0;
	ps->drawend_x = ps->spritewidth / 2 + ps->spritescreen_x;
	if (ps->drawend_x >= par->res_w)
		ps->drawend_x = par->res_w - 1;
}

void		draw_sprites(t_sprite *sprite, t_params *par, t_ray *ray, t_ps *ps)
{
	t_sprite	*tmp;

	tmp = sprite;
	while (tmp)
	{
		ps->sprite_x = tmp->x - ray->start_posx + 0.5;
		ps->sprite_y = tmp->y - ray->start_posy + 0.5;
		ps->invdet = 1.0 / (ray->planx * ray->diry - ray->dirx * ray->plany);
		ps->transform_x = ps->invdet *
			(ray->diry * ps->sprite_x - ray->dirx * ps->sprite_y);
		ps->transform_y = ps->invdet *
			(-ray->plany * ps->sprite_x + ray->planx * ps->sprite_y);
		ps->spritescreen_x = (int)((par->res_w / 2) *
				(1 + ps->transform_x / ps->transform_y));
		ps->spriteheight = abs((int)(par->res_h / (ps->transform_y)));
		draw_limit(par, ps);
		sprite_loop(par, ray, ps);
		tmp = tmp->next;
	}
}

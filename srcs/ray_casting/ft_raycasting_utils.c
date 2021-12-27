/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:38:44 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/27 02:30:20 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

/*
get texture from orientation
*/
t_text	*which_text(int side, t_params *par)
{
	t_text	*tex;

	if (side == NO)
		tex = par->no_text;
	else if (side == SO)
		tex = par->so_text;
	else if (side == EA)
		tex = par->ea_text;
	else
		tex = par->we_text;
	return (tex);
}

/*
get player distance to wall
*/
void	get_wall_dist(t_ray *ray)
{
	if (ray->side == NO || ray->side == SO)
		ray->wall_dist = (ray->map_x - ray->start_posx + \
				(1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->wall_dist = (ray->map_y - ray->start_posy + \
				(1 - ray->step_y) / 2) / ray->ray_dir_y;
}

int	ft_get_pixel(t_text *f, int x, int y)
{
	char	*dst;

	dst = (char *)f->text_img + (y * f->size + x * (f->bpp / 8));
	return (*(unsigned int *)dst);
}

/*
step ray according to direction
*/
void	ft_step(t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (ray->start_posx - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - ray->start_posx) * ray->delta_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (ray->start_posy - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - ray->start_posy) * ray->delta_y;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 05:52:57 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/24 05:52:58 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	ft_ray_par_init(int wind_part, t_params *par, t_ray *ray)
{
	ray->cam_posx = 2 * wind_part / (double)par->res_w - 1;
	ray->ray_dir_x = ray->dirx + ray->planx * ray->cam_posx;
	ray->ray_dir_y = ray->diry + ray->plany * ray->cam_posx;
	ray->map_x = floor(ray->start_posx);
	ray->map_y = floor(ray->start_posy);
	ray->delta_y = fabs(1 / ray->ray_dir_y);
	if (ray->ray_dir_y == 0)
		ray->delta_x = 0;
	else if (ray->ray_dir_x == 0)
		ray->delta_x = 1;
	else
		ray->delta_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_x == 0)
		ray->delta_y = 0;
	else if (ray->ray_dir_y == 0)
		ray->delta_y = 1;
	else
		ray->delta_y = fabs(1 / ray->ray_dir_y);
	ft_step(ray);
}

void	ft_ray_inc(t_params *par, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			if (ray->step_x == 1)
				ray->side = SO;
			else if (ray->step_x == -1)
				ray->side = NO;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			if (ray->step_y == 1)
				ray->side = EA;
			else if (ray->step_y == -1)
				ray->side = WE;
		}
		if (par->map_tab[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
}

void	ft_ray_text(t_params *par, t_ray *ray, int x)
{
	int		i;
	t_text	*tex;
	double	step;
	double	texpos;

	tex = wich_text(ray->side, par);
	ray->tex_x = (int)(ray->wall_x * (double)(tex->w));
	if ((ray->side == NO || ray->side == SO) && ray->ray_dir_x > 0)
		ray->tex_x = tex->w - ray->tex_x - 1;
	if ((ray->side == EA || ray->side == WE) && ray->ray_dir_y > 0)
		ray->tex_x = tex->w - ray->tex_x - 1;
	step = 1.0 * tex->h / ray->line_h;
	texpos = (ray->draw_start - par->res_h / 2 + ray->line_h / 2) * step;
	i = ray->draw_start;
	while (i++ < ray->draw_end)
	{
		ray->tex_y = (int)texpos & (tex->h - 1);
		texpos += step;
		ft_frame_pixel(par, x, i, ft_get_pixel(tex, ray->tex_x, ray->tex_y));
	}
	ray->zbuffer[x] = ray->wall_dist;
}

void	ft_ray_data(t_ray *ray, t_params *par)
{
	get_wall_dist(ray);
	ray->line_h = (int)(par->res_h / ray->wall_dist);
	ray->draw_start = -ray->line_h / 2 + par->res_h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_h / 2 + par->res_h / 2;
	if (ray->draw_end >= par->res_h)
		ray->draw_end = par->res_h - 1;
	if (ray->side == NO || ray->side == SO)
		ray->wall_x = ray->start_posy + ray->wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = ray->start_posx + ray->wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	cast_scene(t_params *par, t_ray *ray)
{
	int		i;

	i = 0;
	while (i < par->res_w)
	{
		ft_ray_par_init(i, par, ray);
		ft_ray_inc(par, ray);
		ft_ray_data(ray, par);
		ft_ray_text(par, ray, i);
		i++;
	}
}

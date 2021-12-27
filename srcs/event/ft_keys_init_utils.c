/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_init_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:35:59 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/27 02:36:04 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	ft_frwrd_bckwrd(t_ray *ray, t_params *par)
{
	if (par->key->w == 1)
	{
		if (par->map_tab[(int)floor(ray->start_posx + ray->dirx * MVS * 2)]
			[(int)floor(ray->start_posy)] != '1')
			par->ray->start_posx += ray->dirx * MVS;
		if (par->map_tab[(int)floor(ray->start_posx)]
			[(int)floor(ray->start_posy + ray->diry * MVS * 2)] != '1')
			par->ray->start_posy += ray->diry * MVS;
	}
	else if (par->key->s == 1)
	{
		if (par->map_tab[(int)floor(ray->start_posx - ray->dirx * MVS * 2)]
			[(int)floor(ray->start_posy)] != '1')
			ray->start_posx -= ray->dirx * MVS;
		if (par->map_tab[(int)floor(ray->start_posx)]
			[(int)floor(ray->start_posy - ray->diry * MVS * 2)] != '1')
			ray->start_posy -= ray->diry * MVS;
	}
}

void	ft_left_right(t_ray *ray, t_params *par)
{
	double		newdirx;
	double		newdiry;

	if (par->key->a)
	{
		newdirx = -ray->diry;
		newdiry = ray->dirx;
		if (par->map_tab[(int)(ray->start_posx + newdirx * MVS * 2)]
			[(int)ray->start_posy] != '1')
			ray->start_posx += newdirx * MVS;
		if (par->map_tab[(int)ray->start_posx]
			[(int)(ray->start_posy + newdiry * MVS * 2)] != '1')
			ray->start_posy += newdiry * MVS;
	}
	else if (par->key->d)
	{
		newdirx = ray->diry;
		newdiry = -ray->dirx;
		if (par->map_tab[(int)(ray->start_posx + newdirx * MVS * 2)]
			[(int)ray->start_posy] != '1')
			ray->start_posx += newdirx * MVS;
		if (par->map_tab[(int)ray->start_posx]
			[(int)(ray->start_posy + newdiry * MVS * 2)] != '1')
			ray->start_posy += newdiry * MVS;
	}
}

void	ft_rotation(t_ray *ray, t_params *par)
{
	double	oldirx;
	double	oldplanx;

	if (par->key->rgt_ar == 1)
	{
		oldirx = ray->dirx;
		ray->dirx = ray->dirx * cos(-ROTS) - ray->diry * sin(-ROTS);
		ray->diry = oldirx * sin(-ROTS) + ray->diry * cos(-ROTS);
		oldplanx = ray->planx;
		ray->planx = ray->planx * cos(-ROTS) - ray->plany * sin(-ROTS);
		ray->plany = oldplanx * sin(-ROTS) + ray->plany * cos(-ROTS);
	}
	if (par->key->lft_ar == 1)
	{
		oldirx = ray->dirx;
		ray->dirx = ray->dirx * cos(ROTS) - ray->diry * sin(ROTS);
		ray->diry = oldirx * sin(ROTS) + ray->diry * cos(ROTS);
		oldplanx = ray->planx;
		ray->planx = ray->planx * cos(ROTS) - ray->plany * sin(ROTS);
		ray->plany = oldplanx * sin(ROTS) + ray->plany * cos(ROTS);
	}
}

int	ft_movement(t_params *par)
{
	ft_frwrd_bckwrd(par->ray, par);
	ft_left_right(par->ray, par);
	ft_rotation(par->ray, par);
	return (0);
}

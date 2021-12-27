/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:35:23 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/27 01:35:24 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_init_dir(t_params *par)
{
	if (par->player_pos->dir == 'N')
	{
		par->ray->dirx = -1.0;
		par->ray->plany = 0.66;
	}
	else if (par->player_pos->dir == 'S')
	{
		par->ray->dirx = 1.0;
		par->ray->plany = -0.66;
	}
	else if (par->player_pos->dir == 'W')
	{
		par->ray->diry = -1.0;
		par->ray->planx = -0.66;
	}
	else if (par->player_pos->dir == 'E')
	{
		par->ray->diry = 1.0;
		par->ray->planx = 0.66;
	}
}

void	ft_dflt_ray_data(t_ray *ray)
{
	ray->cam_posx = 0;
	ray->start_posx = 0;
	ray->start_posy = 0;
	ray->time = 0;
	ray->old_time = 0;
	ray->dirx = 0;
	ray->diry = 0;
	ray->planx = 0;
	ray->plany = 0;
	ray->ray_dir_y = 0;
	ray->ray_dir_x = 0;
	ray->side_x = 0;
	ray->side_y = 0;
	ray->delta_x = 0;
	ray->delta_y = 0;
	ray->wall_dist = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->line_h = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	ft_dlft_key(t_key *key)
{
	key->w = 0;
	key->a = 0;
	key->d = 0;
	key->s = 0;
	key->esc = 0;
	key->lft_ar = 0;
	key->rgt_ar = 0;
}

void	ft_init_gen(t_params *par)
{
	ft_init_params(par);
	par->ray = malloc(sizeof(t_ray) * 1);
	par->key = malloc(sizeof(t_key) * 1);
	par->ps = malloc(sizeof(t_ps) * 1);
	par->mlx_id = mlx_init();
	if (!par->ray)
		ft_quit("Failed ray struct malloc. \n", par);
	if (!par->key)
		ft_quit("Failed key struct malloc. \n", par);
	if (!par->ps)
		ft_quit("Failed ps struct malloc. \n", par);
	ft_dlft_key(par->key);
	ft_dflt_ray_data(par->ray);
	par->ray->zbuffer = NULL;
	if (!par->mlx_id)
		ft_quit("Failed to init mlx_id. \n", par);
	par->no_text = ft_init_text();
	par->so_text = ft_init_text();
	par->ea_text = ft_init_text();
	par->we_text = ft_init_text();
	par->sprit_text = ft_init_text();
}

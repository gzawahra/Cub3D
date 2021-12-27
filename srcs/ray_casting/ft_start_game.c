/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:39:07 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/27 02:34:40 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	ft_raycast_handle(t_params *par)
{
	par->img_id = mlx_new_image(par->mlx_id, par->res_w, par->res_h);
	if (!par->img_id)
		ft_quit("Failed to create new image. \n", par);
	par->addr = mlx_get_data_addr(par->img_id, &par->bpp, &par->line_length,
			&par->endian);
	ft_cast_flcl(par);
	sort_sprites(par->sprite, par);
	cast_scene(par, par->ray);
	draw_sprites(par->sprite, par, par->ray, par->ps);
}

int	ft_scene(t_params *par)
{
	ft_movement(par);
	ft_raycast_handle(par);
	mlx_put_image_to_window(par->mlx_id, par->window_id, par->img_id, 0, 0);
	mlx_destroy_image(par->mlx_id, par->img_id);
	return (0);
}

void	ft_game_starter(t_params *par)
{
	par->ray->start_posx = par->player_pos->x + 0.5;
	par->ray->start_posy = par->player_pos->y + 0.5;
	ft_init_dir(par);
	par->window_id = mlx_new_window(par->mlx_id, par->res_w,
			par->res_h, "Cub3D");
	if (!par->window_id)
		ft_quit("Mlx window creation failed. \n", par);
	mlx_hook(par->window_id, 33, 1L << 17, &ft_close, par);
	mlx_hook(par->window_id, 2, 1L << 0, &key_press, par);
	mlx_hook(par->window_id, 3, 1L << 1, &key_rel, par);
	mlx_loop_hook(par->mlx_id, ft_scene, par);
	mlx_loop(par->mlx_id);
}

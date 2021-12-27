/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:35:15 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/27 02:15:11 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_free_all(t_params *par)
{
	free_text(par->no_text);
	free_text(par->so_text);
	free_text(par->we_text);
	free_text(par->ea_text);
	free_text(par->sprit_text);
	free(par->line);
	free(par->player_pos);
	if (par->ray && par->ray->zbuffer)
		free(par->ray->zbuffer);
	free(par->ray);
	free(par->key);
	free_sprites(par->sprite);
	if (par->map_tab)
		free_map(par);
	if (par->map)
		free_map_list(par->map);
	if (par->ps)
		free(par->ps);
	if (par->fl_color)
		free(par->fl_color);
	if (par->ceil_color)
		free(par->ceil_color);
}

int	ft_clear(t_params *par)
{
	if (par->we_text && par->we_text->text_id)
		mlx_destroy_image(par->mlx_id, par->we_text->text_id);
	if (par->ea_text && par->ea_text->text_id)
		mlx_destroy_image(par->mlx_id, par->ea_text->text_id);
	if (par->so_text && par->so_text->text_id)
		mlx_destroy_image(par->mlx_id, par->so_text->text_id);
	if (par->no_text && par->no_text->text_id)
		mlx_destroy_image(par->mlx_id, par->no_text->text_id);
	if (par->sprit_text && par->sprit_text->text_id)
		mlx_destroy_image(par->mlx_id, par->sprit_text->text_id);
	if (par->window_id)
		mlx_destroy_window(par->mlx_id, par->window_id);
	return (0);
}

void	ft_error_display(char *msg)
{
	int		len;

	len = ft_strlen(msg);
	if (!msg)
		return ;
	write(2, "Error :  \n", 6);
	write(2, msg, len);
}

void	ft_quit(char *msg, t_params *par)
{
	if (msg)
		ft_error_display(msg);
	if (par)
	{
		ft_clear(par);
		ft_free_all(par);
		if (par->mlx_id)
		{
			mlx_destroy_display(par->mlx_id);
			free(par->mlx_id);
		}
		free(par);
	}
	exit(0);
}

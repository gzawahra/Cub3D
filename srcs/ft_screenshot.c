/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 05:50:58 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/24 05:51:00 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include <fcntl.h>

unsigned int	ft_pixel(t_params *par, int x, int y)
{
	char	*dst;

	dst = par->addr + (y * par->line_length + x * (par->bpp / 8));
	return (*(unsigned int *)dst);
}

void			ft_header(t_params *par, int fd)
{
	int		tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * par->res_w * par->res_h;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &par->res_w, 4);
	write(fd, &par->res_h, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &par->bpp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void			ft_img(int fd, t_params *par)
{
	int	y;
	int	x;
	int	color;

	y = par->res_h;
	while (y--)
	{
		x = 0;
		while (x < par->res_w)
		{
			color = ft_pixel(par, x, y);
			write(fd, &color, 4);
			x++;
		}
	}
}

int				save_bmp(t_params *par)
{
	int		fd;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY, S_IRWXU |
			S_IRWXG | S_IRWXO);
	if (fd < 0)
		ft_quit("Can't open file ./screenshot.bmp", par);
	ft_header(par, fd);
	ft_img(fd, par);
	close(fd);
	return (0);
}

void			ft_screenshot(t_params *par)
{
	par->ray->start_posx = par->player_pos->x + 0.5;
	par->ray->start_posy = par->player_pos->y + 0.5;
	ft_init_dir(par);
	ft_raycast_handle(par);
	save_bmp(par);
	mlx_destroy_image(par->mlx_id, par->img_id);
	ft_quit(NULL, par);
}

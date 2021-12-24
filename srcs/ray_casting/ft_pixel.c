/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 05:53:13 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/24 05:53:14 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	ft_frame_pixel(t_params *par, int x, int y, int color)
{
	char	*dst;

	dst = par->addr + (y * par->line_length + x * (par->bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_trace_line(t_params *par, int x, int y, int color)
{
	int	i;

	i = 0;
	while (i < x)
		ft_frame_pixel(par, i++, y, color);
}

int		ft_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_cast_flcl(t_params *par)
{
	int fl;
	int cl;
	int y;

	y = 0;
	fl = ft_rgb(0, par->fl_color[0], par->fl_color[1], par->fl_color[2]);
	cl = ft_rgb(0, par->ceil_color[0], par->ceil_color[1], par->ceil_color[2]);
	while (y < (par->res_h / 2))
		ft_trace_line(par, par->res_w, y++, cl);
	while (y < (par->res_h))
		ft_trace_line(par, par->res_w, y++, fl);
}

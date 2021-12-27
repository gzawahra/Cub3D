/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:37:17 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/27 01:37:18 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	ft_set_res(t_params *par, char *line)
{
	int		i;
	int		w_max;
	int		h_max;

	w_max = 0;
	h_max = 0;
	i = 0;
	mlx_get_screen_size(par->mlx_id, &w_max, &h_max);
	if (par->res_w != 0 && par->res_h != 0)
		ft_quit("Resolution already defined. \n", par);
	par->res_w = ft_atoi(line);
	if (par->res_w > w_max)
		par->res_w = w_max;
	while (line[i] == 32)
		i++;
	while (ft_isdigit(line[i]) == 1)
		i++;
	par->res_h = ft_atoi(line + i);
	if (par->res_h > h_max)
		par->res_h = h_max;
	if (par->res_h < 1 || par->res_w < 1)
		ft_quit("Window size too small. \n", par);
}

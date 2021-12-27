/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:42:00 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/27 01:42:01 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_params	*params;

	if (ac == 1)
		ft_quit("No map file specified. \n", NULL);
	else if (ac > 2)
		ft_quit("Wrong number of args. \n", NULL);
	params = malloc(sizeof(t_params) * 1);
	if (!params)
		ft_quit("Malloc fail X(. \n", params);
	ft_init_gen(params);
	ft_get_params(params, av[1]);
	ft_valid_params(params);
	params->ray->zbuffer = malloc(sizeof(double) * params->res_w);
	if (!params->ray->zbuffer)
		ft_quit("Malloc fail X(. \n", params);
	ft_game_starter(params);
	return (0);
}

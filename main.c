/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 05:54:29 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/24 05:54:30 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_check_arg(t_params *par, int ac, char **av)
{
	par->save_opt = 0;
	if (ac == 3 && !ft_strcmp(av[2], "--save"))
		par->save_opt = 1;
	else if (ac == 3 && ft_strcmp(av[2], "--save") != 0)
	{
		free(par);
		ft_quit("Wrong saving arg\n", NULL);
	}
}

int		main(int ac, char **av)
{
	t_params	*params;

	if (ac == 1)
		ft_quit("No map file\n", NULL);
	else if (ac > 3)
		ft_quit("Wrong number of arg\n", NULL);
	if (!(params = malloc(sizeof(t_params) * 1)))
		ft_quit("Failed malloc\n", params);
	ft_check_arg(params, ac, av);
	ft_init_gen(params);
	ft_get_params(params, av[1]);
	ft_valid_params(params);
	if (!(params->ray->zbuffer = malloc(sizeof(double) * params->res_w)))
		ft_quit("Failed malloc\n", params);
	if (params->save_opt == 1)
		ft_screenshot(params);
	ft_game_starter(params);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 05:52:04 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/24 05:52:06 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int		ft_save_pos(int x, int y, t_params *par)
{
	if (par->map_tab[x][y] == '2')
		ft_get_spr_pos(&par->sprite, x, y);
	else if (ft_is_valid_char("NSEW", par->map_tab[x][y]) == SUCCESS)
	{
		if (par->player_pos != NULL)
			ft_quit("2 joueur au depart de la map\n", par);
		par->player_pos = ft_set_position(x, y, par->map_tab[x][y]);
		par->map_tab[x][y] = '0';
	}
	return (SUCCESS);
}

int		ft_check_around(int x, int y, char **map)
{
	if (map[x][y + 1] == ' ' || map[x][y + 1] == '\0')
		return (ERROR);
	else if (map[x][y - 1] == ' ' || map[x][y - 1] == '\0')
		return (ERROR);
	else if (map[x + 1][y] == ' ' || map[x + 1][y] == '\0')
		return (ERROR);
	else if (map[x - 1][y] == ' ' || map[x - 1][y] == '\0')
		return (ERROR);
	else if (map[x - 1][y + 1] == ' ' || map[x - 1][y + 1] == '\0')
		return (ERROR);
	else if (map[x - 1][y - 1] == ' ' || map[x - 1][y - 1] == '\0')
		return (ERROR);
	else if (map[x + 1][y + 1] == ' ' || map[x + 1][y + 1] == '\0')
		return (ERROR);
	else if (map[x + 1][y - 1] == ' ' || map[x + 1][y - 1] == '\0')
		return (ERROR);
	else
		return (SUCCESS);
}

int		ft_firstnlast_line(char *line)
{
	int i;

	i = 0;
	if (line[0] == '\0')
		return (ERROR);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int		ft_firstnlast_char(char *line)
{
	int i;
	int max;

	i = 0;
	max = ft_strlen(line) - 1;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[max] != '\0' && line[max] == ' ')
		max--;
	if (max == 0)
		return (ERROR);
	if (line[max] != '1' || line[i] != '1')
		return (ERROR);
	return (max);
}

int		ft_check_inbtween(int x, t_params *par)
{
	int y;
	int max;

	y = 0;
	max = ft_firstnlast_char(par->map_tab[x]);
	if (max == -1)
		return (ERROR);
	while (y <= max)
	{
		if (ft_is_valid_char(" 012NSEW", par->map_tab[x][y]) == ERROR)
			return (ERROR);
		if (ft_is_valid_char("02NSEW", par->map_tab[x][y]) == SUCCESS)
		{
			if (ft_save_pos(x, y, par) == ERROR)
				return (ERROR);
			if (ft_check_around(x, y, par->map_tab) == ERROR)
				return (ERROR);
		}
		y++;
	}
	return (SUCCESS);
}

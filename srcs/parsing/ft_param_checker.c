/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:37:08 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/27 02:38:52 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	ft_is_valid_map(t_params *par)
{
	int		x;

	x = 0;
	while (par->map_tab[x])
	{
		if (par->map_tab[x][0] == '\0')
			return (ERROR);
		x++;
	}
	x = 0;
	if (ft_firstnlast_line(par->map_tab[x]) == ERROR)
		return (ERROR);
	x++;
	while (x < par->m_size - 1)
	{
		if (ft_check_inbtween(x, par) == ERROR)
			return (ERROR);
		x++;
	}
	if (ft_firstnlast_line(par->map_tab[x]) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	ft_is_valid_char(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (SUCCESS);
		i++;
	}
	return (ERROR);
}

void	ft_valid_color(int *color, t_params *par)
{
	int		i;

	i = 0;
	if (par->fl_color == NULL || par->ceil_color == NULL)
		ft_quit("Missing info for F or C. \n", par);
	while (i < 3)
	{
		if (color[i] < 0 && color[i] > 255)
			ft_quit("Color needs to be between 0 and 255. \n", par);
		i++;
	}
}

int	ft_is_valid_file(t_params *par, const char *filepath)
{
	int		fd;
	int		len;

	len = ft_strlen(filepath) - 4;
	if (ft_strrchr(&filepath[len], '.') == NULL)
		ft_quit("file needs to be of.cub extension.\n", par);
	fd = open(filepath, O_RDONLY);
	if (fd < 3)
		ft_quit("File access error. \n", par);
	return (fd);
}

void	ft_valid_params(t_params *par)
{
	ft_check_text(par, par->no_text);
	ft_check_text(par, par->ea_text);
	ft_check_text(par, par->we_text);
	ft_check_text(par, par->so_text);
	ft_check_text(par, par->sprit_text);
	ft_valid_color(par->fl_color, par);
	ft_valid_color(par->ceil_color, par);
	if (par->res_w == 0 || par->res_h == 0)
		ft_quit("Resolustion defintion missing. \n", par);
	if (par->player_pos == NULL)
		ft_quit("No player defined in map. \n", par);
}

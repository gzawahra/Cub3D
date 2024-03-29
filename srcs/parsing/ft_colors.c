/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:36:17 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/27 01:36:18 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	ft_chr_char(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		if (str[i] == ',' && ft_isdigit(str[i + 1]) != 1)
			return (ERROR);
		if ((str[i] != ' ' && str[i] != ',') && ft_isdigit(str[i]) == 0)
			return (ERROR);
		i++;
	}
	if (count != 2)
		return (ERROR);
	return (SUCCESS);
}

int	*ft_get_color(char *trim)
{
	int		i;
	int		*color;

	i = 0;
	color = (int *)malloc(sizeof(int) * 3);
	if (!color)
		return (NULL);
	while (i < 3)
	{
		color[i] = -1;
		i++;
	}
	i = 0;
	color[0] = ft_atoi(trim);
	while (ft_isdigit(trim[i]) == 1)
		i++;
	if (trim[i] == ',')
		i++;
	color[1] = ft_atoi(trim + i);
	while (ft_isdigit(trim[i]) == 1)
		i++;
	if (trim[i] == ',')
		i++;
	color[2] = ft_atoi(trim + i);
	return (color);
}

void	ft_floor_color(t_params *par, const char *line)
{
	char	*trim;

	if (par->fl_color != NULL)
		ft_quit("Floor color already defined. \n", par);
	trim = ft_str_char_trim(line, ' ');
	if (ft_chr_char(trim) == ERROR)
		ft_quit("Bad floor color. \n", par);
	par->fl_color = ft_get_color(trim);
	free(trim);
}

void	ft_ceil_color(t_params *par, const char *line)
{
	char	*trim;

	if (par->ceil_color != NULL)
		ft_quit("Ceiling color already initialised. \n", par);
	trim = ft_str_char_trim(line, ' ');
	if (ft_chr_char(trim) == ERROR)
		ft_quit("Bad ceiling color. \n", par);
	par->ceil_color = ft_get_color(trim);
	free(trim);
}

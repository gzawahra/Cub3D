/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:36:24 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/27 01:36:25 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	ft_is_map(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_get_map(t_params *par, const char *line)
{
	char	*tmp;

	tmp = ft_strdup(line);
	ft_lstadd_back(&(par->map), (void *)tmp);
	par->m_size++;
}

char	**ft_map_tab(t_params *par)
{
	char	**map_tab;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = par->map;
	map_tab = (char **)malloc(sizeof(char *) * (par->m_size + 1));
	if (!map_tab)
		return (NULL);
	while (par && tmp)
	{
		map_tab[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	map_tab[i] = NULL;
	return (map_tab);
}

void	ft_settings(t_params *par, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		ft_set_res(par, &line[2]);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		ft_set_text(&line[2], par, par->no_text);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		ft_set_text(&line[2], par, par->so_text);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		ft_set_text(&line[2], par, par->we_text);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		ft_set_text(&line[2], par, par->ea_text);
	else if (line[0] == 'S' && line[1] == ' ')
		ft_set_text(&line[1], par, par->sprit_text);
	else if (line[0] == 'C' && line[1] == ' ')
		ft_ceil_color(par, &line[2]);
	else if (line[0] == 'F' && line[1] == ' ')
		ft_floor_color(par, &line[2]);
	else if (ft_is_map(line) == 1)
		par->map_start = 1;
	else if (ft_is_valid_char("RNSWECF ", line[0]) == ERROR)
		ft_quit("Bad char. \n", par);
}

void	ft_get_params(t_params *par, const char *filepath)
{
	int		fd;
	int		i;

	fd = ft_is_valid_file(par, filepath);
	while (get_next_line(fd, &par->line))
	{
		i = 0;
		while (par->line[i] == 32)
			i++;
		if (par->line[i] && par->map_start != 1)
			ft_settings(par, par->line);
		if (par->map_start == 1)
			ft_get_map(par, par->line);
		free(par->line);
		par->line = NULL;
	}
	par->map_tab = ft_map_tab(par);
	free(par->line);
	par->line = NULL;
	if (par->fl_color == NULL)
		ft_quit("Bad ceiling definition. \n", par);
	if (par->map_start == 0 || ft_is_valid_map(par) == ERROR)
		ft_quit("Map not valid. \n", par);
	close(fd);
}

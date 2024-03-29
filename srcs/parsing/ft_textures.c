/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:37:27 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/27 01:37:27 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	ft_check_text(t_params *par, t_text *text)
{
	if (text->text_id == NULL)
		ft_quit("Error loading textures. \n", par);
	if (text->text_img == NULL)
		ft_quit("Error loading textures. \n", par);
}

void	ft_set_text(char *line, t_params *par, t_text *text)
{
	if (text->path != NULL)
		ft_quit("Multiple texture path definitions. \n", par);
	text->path = ft_str_char_trim(line, ' ');
	if (!text->path)
		ft_quit("Bad allocation path. \n", par);
	text->text_id = mlx_xpm_file_to_image(par->mlx_id, text->path, &(text->w),
			&(text->h));
	if (text->text_id)
		text->text_img = (int *)mlx_get_data_addr(text->text_id, &text->bpp,
				&text->size, &text->endian);
}

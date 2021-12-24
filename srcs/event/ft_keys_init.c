/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 05:51:12 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/24 05:51:14 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int		ft_close(t_params *par)
{
	ft_quit(NULL, par);
	return (0);
}

int		key_press(int key_code, t_params *par)
{
	if (key_code == KEY_W)
		par->key->w = 1;
	if (key_code == KEY_S)
		par->key->s = 1;
	if (key_code == KEY_A)
		par->key->a = 1;
	if (key_code == KEY_D)
		par->key->d = 1;
	if (key_code == LFT_AR)
		par->key->lft_ar = 1;
	if (key_code == RGT_AR)
		par->key->rgt_ar = 1;
	if (key_code == KEY_ESC)
		ft_quit(NULL, par);
	return (0);
}

int		key_rel(int key_code, t_params *par)
{
	if (key_code == KEY_W)
		par->key->w = 0;
	if (key_code == KEY_S)
		par->key->s = 0;
	if (key_code == KEY_A)
		par->key->a = 0;
	if (key_code == KEY_D)
		par->key->d = 0;
	if (key_code == LFT_AR)
		par->key->lft_ar = 0;
	if (key_code == RGT_AR)
		par->key->rgt_ar = 0;
	if (key_code == KEY_ESC)
		par->key->esc = 0;
	return (0);
}

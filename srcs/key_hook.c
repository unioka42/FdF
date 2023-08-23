/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:34:15 by kokada            #+#    #+#             */
/*   Updated: 2023/08/23 00:06:27 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate(t_fdf *fdf, int key)
{
	if (key == MAIN_PAD_1)
		fdf->pose->rotate_x += 0.1;
	else if (key == MAIN_PAD_2)
		fdf->pose->rotate_x -= 0.1;
	else if (key == MAIN_PAD_3)
		fdf->pose->rotate_y += 0.1;
	else if (key == MAIN_PAD_4)
		fdf->pose->rotate_y -= 0.1;
	else if (key == MAIN_PAD_5)
		fdf->pose->rotate_z += 0.1;
	else if (key == MAIN_PAD_6)
		fdf->pose->rotate_z -= 0.1;
}

static void	move(t_fdf *fdf, int key)
{
	if (key == LEFT_ARROW)
		fdf->pose->positon_x -= 10;
	else if (key == RIGHT_ARROW)
		fdf->pose->positon_x += 10;
	else if (key == UP_ARROW)
		fdf->pose->positon_y -= 10;
	else if (key == DOWN_ARROW)
		fdf->pose->positon_y += 10;
	else if (key == MAIN_PAD_X)
		fdf->pose->positon_z += 1;
	else if (key == MAIN_PAD_Z)
		fdf->pose->positon_z -= 1;
	if (fdf->pose->positon_z < 1)
		fdf->pose->positon_z = 1;
}

int	key_hook(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == ESC)
	{
		free_fdf(fdf);
		exit(0);
	}
	if (key == MAIN_PAD_I)
		fdf->pose->is_iso = 1;
	else if (key == MAIN_PAD_P)
		fdf->pose->is_iso = 0;
	rotate(fdf, key);
	move(fdf, key);
	draws(param);
	return (0);
}

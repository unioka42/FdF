/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:34:15 by kokada            #+#    #+#             */
/*   Updated: 2023/08/20 00:42:38 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(t_fdf *fdf, int key)
{
	if (key == MAIN_PAD_1)
		fdf->pose->rotate_x += 0.05;
	else if (key == MAIN_PAD_2)
		fdf->pose->rotate_x -= 0.05;
	else if (key == MAIN_PAD_3)
		fdf->pose->rotate_y += 0.05;
	else if (key == MAIN_PAD_4)
		fdf->pose->rotate_y -= 0.05;
	else if (key == MAIN_PAD_5)
		fdf->pose->rotate_z += 0.05;
	else if (key == MAIN_PAD_6)
		fdf->pose->rotate_z -= 0.05;
}

void	move(t_fdf *fdf, int key)
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
}

void	key_hook(int key, void *param)
{
	if (key == ESC)
		exit(0);
	rotate((t_fdf *)param, key);
	move((t_fdf *)param, key);
	draws(param);
}

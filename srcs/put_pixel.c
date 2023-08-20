/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:41:33 by kokada            #+#    #+#             */
/*   Updated: 2023/08/20 15:42:11 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int	pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = (y * fdf->display->size_line) + (x * sizeof(int));
		if (fdf->display->endian == 0)
		{
			fdf->display->data_addr[pixel + 0] = (color) & 0xFF;
			fdf->display->data_addr[pixel + 1] = (color >> 8) & 0xFF;
			fdf->display->data_addr[pixel + 2] = (color >> 16) & 0xFF;
			fdf->display->data_addr[pixel + 3] = (color >> 24);
		}
		else if (fdf->display->endian == 1)
		{
			fdf->display->data_addr[pixel + 0] = (color >> 24);
			fdf->display->data_addr[pixel + 1] = (color >> 16) & 0xFF;
			fdf->display->data_addr[pixel + 2] = (color >> 8) & 0xFF;
			fdf->display->data_addr[pixel + 3] = (color) & 0xFF;
		}
	}
}

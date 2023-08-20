/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:44:32 by kokada            #+#    #+#             */
/*   Updated: 2023/08/20 15:15:25 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	allocate_memory(t_fdf **fdf_ptr)
{
	(*fdf_ptr) = (t_fdf *)malloc(sizeof(t_fdf));
	if (*fdf_ptr != NULL)
	{
		(*fdf_ptr)->map = (t_map *)malloc(sizeof(t_map));
		if ((*fdf_ptr)->map != NULL)
		{
			(*fdf_ptr)->display = (t_display *)malloc(sizeof(t_display));
			if ((*fdf_ptr)->display != NULL)
			{
				(*fdf_ptr)->pose = (t_pose *)malloc(sizeof(t_pose));
				if ((*fdf_ptr)->pose != NULL)
					return (1);
				free((*fdf_ptr)->display);
			}
			free((*fdf_ptr)->map);
		}
		free((*fdf_ptr));
	}
	return (-1);
}

int	mlx_display_init(t_display *display)
{
	display->mlx = mlx_init();
	display->win = mlx_new_window(display->mlx, WIDTH, HEIGHT, "FdF");
	display->img = mlx_new_image(display->mlx, WIDTH, HEIGHT);
	display->data_addr = mlx_get_data_addr(display->img,
											&(display->bits_per_pixel),
											&(display->size_line),
											&(display->endian));
	return (0);
}

int	pose_init(t_fdf *fdf)
{
	fdf->pose->is_iso = 1;
	fdf->pose->positon_x = WIDTH / 2;
	fdf->pose->positon_y = HEIGHT / 3;
	fdf->pose->positon_z = ko_min(WIDTH / fdf->map->width / 2, HEIGHT
			/ fdf->map->height / 2);
	if (fdf->pose->positon_z < 1)
		fdf->pose->positon_z = 1;
	fdf->pose->rotate_x = 0;
	fdf->pose->rotate_y = 0;
	fdf->pose->rotate_z = 0;
	fdf->pose->height = 1;
	return (1);
}

void	mlx_hook_init(t_fdf *fdf)
{
	mlx_key_hook(fdf->display->win, key_hook, fdf);
}
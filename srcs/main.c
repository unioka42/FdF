/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:46:07 by kokada            #+#    #+#             */
/*   Updated: 2023/08/22 15:03:23 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <libc.h>

__attribute__((destructor)) static void destructor()
{
	system("leaks -q fdf");
}

int	main(void)
{
	t_fdf *fdf;

	// if (argc != 2)
	// 	ko_error("usege: ./fdf map_file.fdf");
	if (allocate_memory(&fdf) < 0)
		ko_error("malloc err");
	if (read_map("test_maps/42.fdf", fdf->map) < 0)
		ko_error("file map err");
	mlx_display_init(fdf->display);
	pose_init(fdf);
	//draws(fdf);
	mlx_hook_init(fdf);
	mlx_loop(fdf->display->mlx);
	return (0);
}


// int	main(void)
// {
// 	t_fdf *fdf;

// 	// if (argc != 2)
// 	// 	ko_error("usege: ./fdf map_file.fdf");
// 	if (allocate_memory(&fdf) < 0)
// 		ko_error("malloc err");
// 	// if (read_map("test_maps/42.fdf", fdf->map) < 0)
// 	// 	ko_error("file map err");
// 	mlx_display_init(fdf->display);
// 	pose_init(fdf);
// 	draws(fdf);
// 	mlx_hook_init(fdf);
// 	// mlx_loop(fdf->display->mlx);
// 	// mlx_destroy_window(fdf->display->mlx, fdf->display->win);
// 	// mlx_destroy_image(fdf->display->mlx,fdf->display->img);
// 	free_fdf(fdf);
// 	return (0);
// }
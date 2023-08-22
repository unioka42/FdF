/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:46:07 by kokada            #+#    #+#             */
/*   Updated: 2023/08/22 16:59:36 by kokada           ###   ########.fr       */
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
	t_fdf	*fdf;

	// if (argc != 2)
	// 	ko_error("usege: ./fdf map_file.fdf");
	if (allocate_memory(&fdf) < 0)
		ko_error("malloc err", fdf);
	read_map("test_maps/42.fdf", fdf->map, fdf);
	free_fdf(fdf);
	return (0);
	mlx_display_init(fdf->display);
	pose_init(fdf);
	draws(fdf);
	mlx_hook_init(fdf);
	mlx_loop(fdf->display->mlx);
	return (0);
}

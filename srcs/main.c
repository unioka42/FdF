/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:46:07 by kokada            #+#    #+#             */
/*   Updated: 2023/08/23 12:36:03 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = NULL;
	if (argc != 2)
		ko_error("usege: ./fdf map_file.fdf", fdf);
	if (allocate_memory(&fdf) < 0)
		ko_error("malloc err", fdf);
	read_map(argv[1], fdf->map, fdf);
	mlx_display_init(fdf->display);
	pose_init(fdf);
	draws(fdf);
	mlx_hook_init(fdf);
	mlx_loop(fdf->display->mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:46:07 by kokada            #+#    #+#             */
/*   Updated: 2023/08/20 14:25:53 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		ko_error("usege: ./fdf map_file.fdf");
	if (allocate_memory(&fdf) < 0)
		ko_error("malloc err");
	if (read_map(argv[1], fdf->map) < 0)
		ko_error("file map err");
	mlx_display_init(fdf->display);
	pose_init(fdf);
	draws(fdf);
	mlx_hook_init(fdf);
	mlx_loop(fdf->display->mlx);
	return (0);
}

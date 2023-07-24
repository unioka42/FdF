/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:46:07 by kokada            #+#    #+#             */
/*   Updated: 2023/07/24 22:45:37 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	deal_key(int key, t_data *data)
{
	ft_putnbr_fd(key, 1);
	if (key == 126)
		data->display->shift_y -= 10;
	if (key == 125)
		data->display->shift_y += 10;
	if (key == 123)
		data->display->shift_x -= 10;
	if (key == 124)
		data->display->shift_x += 10;
	if (key == 6)
		data->display->a -= 0.05;
	if (key == 7)
		data->display->a += 0.05;
	mlx_clear_window(data->display->mlx, data->display->mlx_win);
	draw(data->map, data->display);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	// if (argc != 2)
	// 	ko_error("usege: ./fdf map_file.fdf");
	data = (t_data *)malloc(sizeof(t_data));
	data->map = read_map("./42.fdf");
	data->display = (t_display *)malloc(sizeof(t_display));
	data->display->mlx = mlx_init();
	data->display->mlx_win = mlx_new_window(data->display->mlx, 1000, 1000,
		"fdf");
	data->display->zoom = 20;
	draw(data->map, data->display);
	mlx_key_hook(data->display->mlx_win, deal_key, data);
	mlx_loop(data->display->mlx);
	return (0);
}

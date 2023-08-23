/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:08:35 by kokada            #+#    #+#             */
/*   Updated: 2023/08/23 11:57:36 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	update_coordinates(int *err, int *put_point_coord, int step,
		int delta)
{
	*err += delta;
	*put_point_coord += step;
}

static void	draw_line(t_point f, t_point s, t_fdf *fdf)
{
	t_point	put_point;
	int		delta[2];
	int		step[2];
	int		err;
	int		e2;

	create_3d_plot(&f, fdf->pose);
	create_3d_plot(&s, fdf->pose);
	delta[0] = abs(s.x - f.x);
	delta[1] = abs(s.y - f.y);
	step[0] = ko_istrue(f.x < s.x, 1, -1);
	step[1] = ko_istrue(f.y < s.y, 1, -1);
	err = delta[0] - delta[1];
	put_point = f;
	while (!(put_point.x == s.x && put_point.y == s.y))
	{
		put_pixel(fdf, put_point.x, put_point.y, set_draw_color(f, s,
				put_point));
		e2 = 2 * err;
		if (e2 > -delta[1])
			update_coordinates(&err, &put_point.x, step[0], -delta[1]);
		if (e2 < delta[0])
			update_coordinates(&err, &put_point.y, step[1], delta[0]);
	}
}

t_point	set_point(int x, int y, t_map *map)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = map->map_list[y][x];
	point.color = map->map_list_color[y][x];
	return (point);
}

void	draws(t_fdf *fdf)
{
	t_map	*map;
	int		x;
	int		y;

	map = fdf->map;
	ft_bzero(fdf->display->data_addr, WIDTH * HEIGHT * sizeof(int));
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(set_point(x, y, map), set_point(x + 1, y, map), fdf);
			if (y < map->height - 1)
				draw_line(set_point(x, y, map), set_point(x, y + 1, map), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->display->mlx, fdf->display->win,
		fdf->display->img, 0, 0);
}

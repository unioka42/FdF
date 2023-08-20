/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:08:35 by kokada            #+#    #+#             */
/*   Updated: 2023/08/20 16:30:02 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	set_precent(int start, int end, float persent)
{
	return (start + ((end - start) * persent));
}

static int	set_color(t_point start, t_point end, t_point put)
{
	float	percent;
	int		r;
	int		g;
	int		b;

	if (start.color == end.color)
		return (start.color);
	if (end.x - start.x > end.y - start.y)
		percent = (float)(put.x - start.x) / (end.x - start.x);
	else
		percent = (float)(put.y - start.y) / (end.y - start.y);
	r = set_precent((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF,
			percent);
	g = set_precent((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF,
			percent);
	b = set_precent(start.color & 0xFF, end.color & 0xFF, percent);
	return ((r << 16) | (g << 8) | b);
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
		put_pixel(fdf, put_point.x, put_point.y, set_color(f, s, put_point));
		e2 = 2 * err;
		if (e2 > -delta[1])
		{
			err -= delta[1];
			put_point.x += step[0];
		}
		if (e2 < delta[0])
		{
			err += delta[0];
			put_point.y += step[1];
		}
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

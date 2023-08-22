/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:28:35 by kokada            #+#    #+#             */
/*   Updated: 2023/08/22 16:44:52 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_result(char **point, char **points, char *err_msg, t_fdf *fdf)
{
	if (point != NULL)
		free_char_list(point, 1);
	free_char_list(points, 1);
	if (err_msg != NULL)
		ko_error(err_msg, fdf);
}

static int	fill(int *z_line, int *color, char *line, t_fdf *fdf)
{
	char	**points;
	char	**point;
	int		i;

	points = ft_split(line, ' ');
	free(line);
	i = 0;
	while (i < fdf->map->width)
	{
		if (points[i] == NULL)
			fill_result(NULL, points, WIDTH_ERR, fdf);
		point = ft_split(points[i], ',');
		if (ko_strisdigit(point[0]) == -1)
			fill_result(point, points, NOT_DIGIT, fdf);
		z_line[i] = ft_atoi(point[0]);
		if (point[1] != NULL)
		{
			if (point[1][0] == '0' && point[1][1] == 'x' && point[2] == NULL)
				color[i] = ft_atoi_base(point[1] + 2, "0123456789abcdef");
			else
				fill_result(point, points, COLOR_ERR, fdf);
		}
		else
			color[i] = 0xffffff;
		free_char_list(point, 1);
		i++;
	}
	if (points[i] != NULL)
		fill_result(NULL, points, WIDTH_ERR, fdf);
	fill_result(NULL, points, NULL, fdf);
	return (0);
}

int	read_map(char *file_path, t_map *map, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	map->height = count_row(file_path);
	line = get_next_line(fd);
	map->width = split_counter(line, ' ');
	if (line[0] == ' ')
		map->width--;
	if (map->height < 0 || map->width < 0)
		return (-2);
	map->map_list = (int **)malloc(sizeof(int *) * (map->height + 1));
	map->map_list_color = (int **)malloc(sizeof(int *) * (map->height + 1));
	if (map->map_list == NULL)
		return (-3);
	i = 0;
	while (i < map->height)
	{
		map->map_list[i] = (int *)malloc(sizeof(int) * (map->width + 1));
		map->map_list[i + 1] = NULL;
		map->map_list_color[i] = (int *)malloc(sizeof(int) * (map->width + 1));
		map->map_list_color[i + 1] = NULL;
		if (fill(map->map_list[i], map->map_list_color[i], line, fdf) < 0)
		{
			return (-4);
		}
		line = get_next_line(fd);
		i++;
	}
	return (1);
}

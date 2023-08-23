/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:28:35 by kokada            #+#    #+#             */
/*   Updated: 2023/08/23 10:02:53 by kokada           ###   ########.fr       */
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

static int	set_color(int i, char **point, int *color)
{
	if (point[1] != NULL)
	{
		if (point[1][0] == '0' && point[1][1] == 'x' && point[2] == NULL)
			color[i] = ft_atoi_base(point[1] + 2, "0123456789abcdef");
		else
			return (-1);
	}
	else
		color[i] = 0xffffff;
	return (0);
}

static void	fill(int *z_line, int *color, char *line, t_fdf *fdf)
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
		if (set_color(i, point, color) < 0)
			fill_result(point, points, COLOR_ERR, fdf);
		free_char_list(point, 1);
		i++;
	}
	if (points[i] != NULL)
		fill_result(NULL, points, WIDTH_ERR, fdf);
	fill_result(NULL, points, NULL, fdf);
}

static void	read_height(t_map *map, int fd, char *line, t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		map->map_list[i] = (int *)malloc(sizeof(int) * (map->width + 1));
		map->map_list[i + 1] = NULL;
		map->map_list_color[i] = (int *)malloc(sizeof(int) * (map->width + 1));
		map->map_list_color[i + 1] = NULL;
		fill(map->map_list[i], map->map_list_color[i], line, fdf);
		line = get_next_line(fd);
		i++;
	}
}

void	read_map(char *file_path, t_map *map, t_fdf *fdf)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ko_error(FD_ERR, fdf);
	map->height = count_row(file_path);
	line = get_next_line(fd);
	if (line == NULL)
		ko_error(MAP_EMPTY, fdf);
	map->width = split_counter(line, ' ');
	if (line[0] == ' ')
		map->width--;
	if (map->height < 2 && map->width < 2)
		ko_error(LOW_DATA, fdf);
	map->map_list = (int **)malloc(sizeof(int *) * (map->height + 1));
	map->map_list_color = (int **)malloc(sizeof(int *) * (map->height + 1));
	if (map->map_list == NULL)
		ko_error(MALLOC_ERR, fdf);
	read_height(map, fd, line, fdf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:28:35 by kokada            #+#    #+#             */
/*   Updated: 2023/08/22 12:53:45 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fill(int *z_line, int *color, char *line, int width)
{
	char	**points;
	char	**point;
	int		i;

	points = ft_split(line, ' ');
	free(line);
	i = 0;
	while (i < width)
	{
		if (points[i] == NULL)
			return (free_char_list(point, -1));
		point = ft_split(points[i], ',');
		if (ko_strisdigit(point[0]) == -1)
			return (free_char_list(point, -1));
		z_line[i] = ft_atoi(point[0]);
		if (point[1] != NULL)
		{
			if (point[1][0] == '0' && point[1][1] == 'x' && point[2] == NULL)
				color[i] = ft_atoi_base(point[1] + 2, "0123456789abcdef");
			else
				return (free_char_list(point, -1));
		}
		else
			color[i] = 0xffffff;
		free_char_list(point, 1);
		free(points[i]);
		i++;
	}
	if (points[i] != NULL)
		return (-1);
	free(points);
	return (0);
}

int	read_map(char *file_path, t_map *map)
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
		if (fill(map->map_list[i], map->map_list_color[i], line,
				map->width) < 0)
		{
			return (-4);
		}
		line = get_next_line(fd);
		i++;
	}
	map->map_list[i] = NULL;
	return (1);
}

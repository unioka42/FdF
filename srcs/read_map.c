/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:28:35 by kokada            #+#    #+#             */
/*   Updated: 2023/07/23 21:09:32 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	fill(int *z_line, char *line, int width)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (i < width)
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

t_map	*read_map(char *file_path)
{
	int		fd;
	char	*line;
	t_map	*tmp;
	int		i;

	tmp = (t_map *)malloc(sizeof(t_map));
	tmp->height = count_row(file_path);
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	tmp->width = split_counter(line, ' ');
	tmp->map_list = (int **)malloc(sizeof(int *) * (tmp->height + 1));
	i = 0;
	while (i < tmp->height)
	{
		tmp->map_list[i] = (int *)malloc(sizeof(int) * (tmp->width + 1));
		fill(tmp->map_list[i], line, tmp->width);
		line = get_next_line(fd);
		i++;
	}
	tmp->map_list[i] = NULL;
	return (tmp);
}

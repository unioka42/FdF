/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 00:20:14 by kokada            #+#    #+#             */
/*   Updated: 2023/07/23 16:08:47 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_row(char *file_path)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file_path, O_RDONLY);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			close(fd);
			return (count);
		}
		count++;
		free(line);
	}
}

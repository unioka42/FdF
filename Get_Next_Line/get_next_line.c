/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:39:30 by kokada            #+#    #+#             */
/*   Updated: 2023/07/23 17:16:32 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read(char **tmp, int fd)
{
	char	*buf;
	char	*tmp_cpy;
	int		read_size;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (-1);
	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size <= 0)
		free(buf);
	if (read_size == -1)
		return (-1);
	if (read_size == 0)
		return (2);
	buf[read_size] = '\0';
	tmp_cpy = ft_strjoin(*tmp, buf);
	free(*tmp);
	*tmp = tmp_cpy;
	free(buf);
	if (*tmp == NULL)
		return (-1);
	return (read_size < BUFFER_SIZE);
}

static char	*get_line_and_tmp(char **tmp, int newline)
{
	char	*line;
	char	*new_tmp;
	int		rest_len;

	line = ft_substr(*tmp, 0, newline + 1);
	if (line == NULL)
		return (NULL);
	rest_len = ft_strlen(*tmp + newline);
	new_tmp = ft_substr(*tmp, newline + 1, rest_len);
	if (new_tmp == NULL)
		return (NULL);
	free(*tmp);
	*tmp = new_tmp;
	return (line);
}

static char	*get_end_line(char **tmp)
{
	char	*res;

	if (*tmp[0] == '\0')
	{
		free(*tmp);
		return (NULL);
	}
	res = *tmp;
	*tmp = NULL;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*tmp[2048];
	int			newline;
	int			read_res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	newline = ft_str_search(tmp[fd], '\n');
	while (newline == -1)
	{
		read_res = ft_read(&tmp[fd], fd);
		if (read_res == -1)
			return (NULL);
		if (read_res == 2 && tmp[fd] == NULL)
			return (NULL);
		newline = ft_str_search(tmp[fd], '\n');
		if (read_res != 0 && newline == -1)
			return (get_end_line(&tmp[fd]));
	}
	return (get_line_and_tmp(&tmp[fd], newline));
}

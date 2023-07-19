/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:39:30 by kokada            #+#    #+#             */
/*   Updated: 2023/06/10 00:30:06 by kokada           ###   ########.fr       */
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
	if (read_size == -1)
	{
		free(buf);
		return (-1);
	}
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

char	*get_next_line(int fd)
{
	static char	*tmp;
	int			newline;
	static int	read_res;

	if (fd < 0 || BUFFER_SIZE < 1 || read_res == 2)
		return (NULL);
	newline = ft_str_search(tmp, '\n');
	while (newline == -1)
	{
		if (read_res == 1 && newline == -1)
		{
			read_res = 2;
			if (tmp[0] != '\0')
				return (tmp);
			free(tmp);
			return (NULL);
		}
		read_res = ft_read(&tmp, fd);
		if (read_res == -1)
			return (NULL);
		newline = ft_str_search(tmp, '\n');
	}
	return (get_line_and_tmp(&tmp, newline));
}

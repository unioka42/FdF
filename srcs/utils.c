/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:11:47 by kokada            #+#    #+#             */
/*   Updated: 2023/08/18 21:15:13 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ko_error(char *error_msg)
{
	ft_putstr_fd(error_msg, 1);
	ft_putchar_fd('\n', 1);
	exit(1);
}

int	ko_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ko_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ko_strisdigit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i++]))
			return (-1);
	}
	return (0);
}

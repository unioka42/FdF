/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:11:47 by kokada            #+#    #+#             */
/*   Updated: 2023/08/22 23:52:08 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ko_error(char *error_msg, t_fdf *fdf)
{
	ft_putstr_fd(error_msg, 1);
	ft_putchar_fd('\n', 1);
	if (fdf != NULL)
		free_fdf(fdf);
	exit(1);
}

int	ko_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ko_istrue(int bool, int true_return, int false_return)
{
	if (bool)
		return (true_return);
	return (false_return);
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

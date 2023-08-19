/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:35:36 by kokada            #+#    #+#             */
/*   Updated: 2023/08/19 12:53:33 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	char_to_num(char str, char *base)
{
	int	i;

	i = 0;
	while (str != base[i])
		i++;
	return (i);
}

int	char_base_checker(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (str == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_putnbr(char *str, char *base, int adic, int negative_count)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0' && char_base_checker(ft_tolower(str[i]), base))
	{
		n = n * adic + char_to_num(ft_tolower(str[i]), base);
		i++;
	}
	if (negative_count % 2 == 1)
		n = -n;
	return (n);
}

int	ft_atoi_strlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '\n' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
			return (0);
		j = 0;
		while (j < i)
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	adic;
	int	i;
	int	negative_count;
	int	n;

	adic = ft_atoi_strlen(base);
	if (adic < 2)
		return (0);
	i = 0;
	negative_count = 0;
	n = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative_count++;
		i++;
	}
	return (ft_putnbr(str + i, base, adic, negative_count));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:28:14 by kokada            #+#    #+#             */
/*   Updated: 2023/05/25 21:32:21 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(int num)
{
	int	digit;

	digit = 1;
	while (num / 10 != 0)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

static void	ft_memadd(char *p, char c, int i)
{
	p[i] = c;
}

static void	ft_putnum(int nb, char *p, int len)
{
	if (nb != 0)
	{
		ft_putnum(nb / 10, p, len - 1);
		ft_memadd(p, nb % 10 + '0', len);
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*p;

	len = ft_digit(n);
	if (n < 0)
		len++;
	p = (char *)malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);
	if (n < 0)
	{
		ft_memadd(p, '-', 0);
		if (n == -2147483648)
		{
			ft_memadd(p, '2', 1);
			n = -147483648;
		}
		n = -n;
	}
	if (n == 0)
		ft_memadd(p, '0', 0);
	ft_putnum(n, p, len - 1);
	ft_memadd(p, '\0', len);
	return (p);
}

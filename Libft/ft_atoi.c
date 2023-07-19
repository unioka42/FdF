/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:47:27 by kokada            #+#    #+#             */
/*   Updated: 2023/05/25 21:20:20 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	overflow_check(long nbr, int next_digit, int sign)
{
	if (sign == 1)
		if ((nbr >= 922337203685477580 && next_digit > 7)
			|| (nbr >= 922337203685477581))
			return (-1);
	if (sign == -1)
		if ((nbr >= 922337203685477580
				&& next_digit > 8) | (nbr >= 922337203685477581))
			return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int		i;
	int		negative;
	long	n;
	int		flag;

	i = 0;
	negative = 1;
	n = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		flag = overflow_check(n, (str[i] - '0'), negative);
		if (flag != 1)
			return (flag);
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return ((int)n * negative);
}

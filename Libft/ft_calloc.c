/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:35:03 by kokada            #+#    #+#             */
/*   Updated: 2023/05/25 21:30:30 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	if (count == 0 || count == 0)
	{
		count = 1;
		size = 1;
	}
	p = (void *)malloc(size * count);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, size * count);
	return (p);
}

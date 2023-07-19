/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:37:54 by kokada            #+#    #+#             */
/*   Updated: 2023/05/25 21:33:23 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	head;
	size_t	tail;
	char	*p;

	head = 0;
	while (s1[head] != '\0' && ft_strchr(set, s1[head]) != NULL)
		head++;
	tail = ft_strlen(s1);
	while (tail != head && ft_strchr(set, s1[tail - 1]) != NULL)
		tail--;
	p = (char *)malloc(sizeof(char) * (tail - head + 1));
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s1 + head, tail - head);
	p[tail - head] = '\0';
	return (p);
}

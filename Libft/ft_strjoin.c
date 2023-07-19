/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:28:12 by kokada            #+#    #+#             */
/*   Updated: 2023/05/25 21:33:00 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		p[s1_len + i] = s2[i];
		i++;
	}
	p[s1_len + s2_len] = '\0';
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:46:01 by kokada            #+#    #+#             */
/*   Updated: 2023/05/23 13:37:57 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	j;
	size_t	dst_len;
	size_t	src_len;
	size_t	result;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dst == NULL)
		return (src_len);
	j = 0;
	while (dst_len + j + 1 < dstsize && src[j] != '\0')
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[dst_len + j] = '\0';
	if (dstsize <= dst_len)
		result = dstsize + src_len;
	else
		result = dst_len + src_len;
	return (result);
}

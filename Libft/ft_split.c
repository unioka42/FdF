/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:15:35 by kokada            #+#    #+#             */
/*   Updated: 2023/05/25 21:25:14 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy_s(const char *s, size_t *start, size_t end, int *flag)
{
	int		i;
	int		size;
	char	*result;

	size = end - (*start);
	result = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	while (i < size)
	{
		result[i] = s[(*start) + i];
		i++;
	}
	result[i] = '\0';
	*flag = 0;
	*start = end + 1;
	return (result);
}

size_t	split_counter(const char *s, char c)
{
	size_t	i;
	int		flag;
	size_t	split_count;

	i = 0;
	split_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (flag)
			{
				split_count++;
				flag = 0;
			}
		}
		else
			flag = 1;
		i++;
	}
	if (flag)
		return (split_count + 1);
	return (split_count);
}

static void	initialize(size_t *i, size_t *start, size_t *split_count, int *flag)
{
	*i = 0;
	*start = 0;
	*split_count = 0;
	*flag = 0;
}

static char	**ft_spliter(char const *s, char c, char **tmp)
{
	size_t	i;
	size_t	start;
	int		flag;
	size_t	split_count;

	initialize(&i, &start, &split_count, &flag);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (flag)
				tmp[split_count++] = copy_s(s, &start, i, &flag);
			else
				start++;
		}
		else
			flag = 1;
		i++;
	}
	if (flag)
		tmp[split_count++] = copy_s(s, &start, i, &flag);
	tmp[split_count] = NULL;
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;

	tmp = (char **)malloc((split_counter(s, c) + 1) * sizeof(char *));
	if (tmp == NULL)
		return (NULL);
	return (ft_spliter(s, c, tmp));
}

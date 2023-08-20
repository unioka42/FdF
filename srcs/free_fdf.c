/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:43:39 by kokada            #+#    #+#             */
/*   Updated: 2023/08/20 17:56:04 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_char_list(char **list, int status)
{
	int	i;

	if (list == NULL)
		return (status);
	i = 0;
	while (list[i] != NULL)
		free(list[i++]);
	free(list);
	return (status);
}

int	free_int_list(int **list, int status)
{
	int	i;

	if (list == NULL)
		return (status);
	i = 0;
	while (list[i] != NULL)
		free(list[i++]);
	free(list);
	return (status);
}

void	free_fdf(t_fdf *fdf)
{
	free(fdf->pose);
	free(fdf->display);
	if (fdf->map->map_list != NULL)
		free_int_list(fdf->map->map_list, 1);
	if (fdf->map->map_list_color != NULL)
		free_int_list(fdf->map->map_list_color, 1);
	free(fdf->map);
	free(fdf);
}

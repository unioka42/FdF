/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:43:39 by kokada            #+#    #+#             */
/*   Updated: 2023/08/24 15:13:09 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_array(void **list)
{
	int	i;

	if (list == NULL)
		return ;
	i = 0;
	while (list[i] != NULL)
		free(list[i++]);
	free(list);
}

void	free_fdf(t_fdf *fdf)
{
	if (fdf->display->mlx != NULL)
	{
		mlx_destroy_window(fdf->display->mlx, fdf->display->win);
		mlx_destroy_image(fdf->display->mlx, fdf->display->img);
		free(fdf->display->mlx);
	}
	free(fdf->pose);
	free(fdf->display);
	if (fdf->map->map_list != NULL)
		free_array((void **)fdf->map->map_list);
	if (fdf->map->map_list_color != NULL)
		free_array((void **)fdf->map->map_list_color);
	free(fdf->map);
	free(fdf);
}

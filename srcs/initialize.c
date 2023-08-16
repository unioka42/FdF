/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:44:32 by kokada            #+#    #+#             */
/*   Updated: 2023/08/16 10:28:52 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	allocate_memory(t_fdf **fdf_ptr)
{
	(*fdf_ptr) = (t_fdf *)malloc(sizeof(t_fdf));
	if (*fdf_ptr != NULL)
	{
		(*fdf_ptr)->map = (t_map *)malloc(sizeof(t_map));
		if ((*fdf_ptr)->map != NULL)
		{
			(*fdf_ptr)->display = (t_display *)malloc(sizeof(t_display));
			if ((*fdf_ptr)->display != NULL)
			{
				(*fdf_ptr)->camera = (t_camera *)malloc(sizeof(t_camera));
				if ((*fdf_ptr)->camera != NULL)
					return (1);
				free((*fdf_ptr)->display);
			}
			free((*fdf_ptr)->map);
		}
		free((*fdf_ptr));
	}
	return (-1);
}

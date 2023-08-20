/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_3d_plot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:29:02 by kokada            #+#    #+#             */
/*   Updated: 2023/08/20 14:13:06 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(int *y, int *z, double rotate_x)
{
	int	tmp_y;

	tmp_y = *y;
	*y = tmp_y * cos(rotate_x) + *z * sin(rotate_x);
	*z = -tmp_y * sin(rotate_x) + *z * cos(rotate_x);
}

static void	rotate_y(int *x, int *z, double rotate_y)
{
	int	tmp_x;

	tmp_x = *x;
	*x = tmp_x * cos(rotate_y) + *z * sin(rotate_y);
	*z = -tmp_x * sin(rotate_y) + *z * cos(rotate_y);
}

static void	rotate_z(int *x, int *y, double rotate_z)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = tmp_x * cos(rotate_z) - tmp_y * sin(rotate_z);
	*y = tmp_x * sin(rotate_z) + tmp_y * cos(rotate_z);
}

static void	isometric(int *x, int *y, int z)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x - tmp_y) * cos(0.523599);
	*y = -z + (tmp_x + tmp_y) * sin(0.523599);
}

void	create_3d_plot(t_point *p, t_pose *pose, t_map *map)
{
	p->x *= pose->positon_z;
	p->y *= pose->positon_z;
	p->z *= pose->positon_z * pose->height;
	rotate_x(&p->y, &p->z, pose->rotate_x);
	rotate_y(&p->x, &p->z, pose->rotate_y);
	rotate_z(&p->x, &p->y, pose->rotate_z);
	if (pose->is_iso)
		isometric(&p->x, &p->y, p->z);
	p->x += pose->positon_x;
	p->y += pose->positon_y;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_draw_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:41:59 by kokada            #+#    #+#             */
/*   Updated: 2023/08/23 10:47:16 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	set_precent(int start, int end, float persent)
{
	return (start + ((end - start) * persent));
}

int	set_draw_color(t_point start, t_point end, t_point put)
{
	float	percent;
	int		r;
	int		g;
	int		b;

	if (start.color == end.color)
		return (start.color);
	if (end.x - start.x > end.y - start.y)
		percent = (float)(put.x - start.x) / (end.x - start.x);
	else
		percent = (float)(put.y - start.y) / (end.y - start.y);
	r = set_precent((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF,
			percent);
	g = set_precent((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF,
			percent);
	b = set_precent(start.color & 0xFF, end.color & 0xFF, percent);
	return ((r << 16) | (g << 8) | b);
}

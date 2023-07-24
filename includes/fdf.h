/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:24:16 by kokada            #+#    #+#             */
/*   Updated: 2023/07/24 22:22:35 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../Get_Next_Line/get_next_line.h"
# include "../Libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "mlx.h"

typedef struct s_map
{
	int			width;
	int			height;
	int			**map_list;
}				t_map;

typedef struct s_display
{
	void		*mlx;
	void		*mlx_win;

	int			zoom;
	int			shift_x;
	int			shift_y;
	float		a;
}				t_display;

typedef struct s_data
{
	t_map		*map;
	t_display	*display;
}				t_data;

t_map			*read_map(char *file_path);
void			ko_error(char *error_msg);
int				count_row(char *file_path);

void			bresenham(float x, float y, float x1, float y1, t_map *data,
					t_display *display);
void			draw(t_map *map, t_display *display);

#endif
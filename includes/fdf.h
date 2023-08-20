/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:24:16 by kokada            #+#    #+#             */
/*   Updated: 2023/08/20 15:08:21 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../Get_Next_Line/get_next_line.h"
# include "../Libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "math.h"

// window_size
# define WIDTH 1280
# define HEIGHT 720
// key_map
# define ESC 53
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126
# define MAIN_PAD_0 29
# define MAIN_PAD_1 18
# define MAIN_PAD_2 19
# define MAIN_PAD_3 20
# define MAIN_PAD_4 21
# define MAIN_PAD_5 23
# define MAIN_PAD_6 22
# define MAIN_PAD_Z 6
# define MAIN_PAD_X 7
# define MAIN_PAD_I 34
# define MAIN_PAD_P 35

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct s_map
{
	int			width;
	int			height;
	int			**map_list;
	int			**map_list_color;
}				t_map;

typedef struct s_pose
{
	int			is_iso;
	int			positon_x;
	int			positon_y;
	int			positon_z;
	float		rotate_x;
	float		rotate_y;
	float		rotate_z;
	float		height;
}				t_pose;

typedef struct s_display
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_display;

typedef struct s_fdf
{
	t_map		*map;
	t_display	*display;
	t_pose		*pose;
}				t_fdf;

int				read_map(char *file_path, t_map *map);
int				count_row(char *file_path);
void			draws(t_fdf *fdf);
void			create_3d_plot(t_point *p, t_pose *pose, t_map *map);
int				ft_atoi_base(char *str, char *base);
void			key_hook(int key, void *param);
// initialize.c
int				allocate_memory(t_fdf **fdf_ptr);
void			mlx_hook_init(t_fdf *fdf);
int				mlx_display_init(t_display *display);
int				pose_init(t_fdf *fdf);
// utils.c
void			ko_error(char *error_msg);
int				ko_min(int a, int b);
size_t			ko_strlen(const char *s);
int				ko_strisdigit(char *s);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:24:16 by kokada            #+#    #+#             */
/*   Updated: 2023/08/24 15:08:09 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../Get_Next_Line/get_next_line.h"
# include "../Libft/libft.h"
# include "../minilibx_linux/mlx.h"
# include "math.h"

// window_size
# define WIDTH 1280
# define HEIGHT 720
// key_map-minilibx_linux
# define ESC 65307
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define DOWN_ARROW 65364
# define UP_ARROW 65362
# define MAIN_PAD_1 49
# define MAIN_PAD_2 50
# define MAIN_PAD_3 51
# define MAIN_PAD_4 52
# define MAIN_PAD_5 53
# define MAIN_PAD_6 54
# define MAIN_PAD_Z 122
# define MAIN_PAD_X 120
# define MAIN_PAD_I 105
# define MAIN_PAD_P 112
// err_msg
# define COLOR_ERR "color error"
# define NOT_DIGIT "not digit"
# define WIDTH_ERR "width error"
# define FD_ERR "file read error"
# define MAP_ERR "map error"
# define MALLOC_ERR "malloc error"
# define MAP_EMPTY "file is empty"
# define LOW_DATA "At least two points are needed"

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

void			read_map(char *file_path, t_map *map, t_fdf *fdf);
int				count_row(char *file_path);
void			draws(t_fdf *fdf);
void			create_3d_plot(t_point *p, t_pose *pose);
void			put_pixel(t_fdf *fdf, int x, int y, int color);
int				ft_atoi_base(char *str, char *base);
int				key_hook(int key, void *param);
void			free_fdf(t_fdf *fdf);
void			free_array(void **list);
int				set_draw_color(t_point start, t_point end, t_point put);
// initialize.c
int				allocate_memory(t_fdf **fdf_ptr);
void			mlx_hook_init(t_fdf *fdf);
int				mlx_display_init(t_display *display);
int				pose_init(t_fdf *fdf);
// utils.c
void			ko_error(char *error_msg, t_fdf *fdf);
int				ko_min(int a, int b);
int				ko_istrue(int bool, int true_return, int false_return);
size_t			ko_strlen(const char *s);
int				ko_strisdigit(char *s);

#endif
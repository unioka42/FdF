/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:24:16 by kokada            #+#    #+#             */
/*   Updated: 2023/07/23 19:13:04 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../Get_Next_Line/get_next_line.h"
# include "../Libft/libft.h"
# include "mlx.h"

typedef struct s_map
{
	int		width;
	int		hight;
	int		**map_list;

	void	*mlx_ptr;
	void	*win_ptr;
}			t_map;

t_map		*read_map(char *file_path);
void		ko_error(char *error_msg);
int			count_row(char *file_path);

#endif
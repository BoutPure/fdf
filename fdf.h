/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:35:15 by vseel             #+#    #+#             */
/*   Updated: 2021/12/13 17:26:57 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
// # include <mlx.h>
# include "minilibx_macos/mlx.h"
// # include "minilibx_macos/mlx_int.h"
// # include "minilibx_macos/mlx_new_window.h"
# include "map_parser/gnl_split_atoi.h"
# include "list_utils/list_utils.h"

typedef struct s_coord
{
	int		x;
	int		y;
	int		x_s;
	int		y_s;
	int		x_s_next_elem;
	int		x_s_next_line;
	int		y_s_next_elem;
	int		y_s_next_line;
	int		x_start;
	int		y_start;
	int		x_end;
	int		y_end;
	float	intery;
	float	gradient;
}			t_coord;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;	
	int		scale_x;
	int		scale_y;
	int		scale_z;
	int		bias_x;
	int		bias_y;
	int		color_flat;
	int		color_high;
	int		color_low;
	int		color_this;
	int		color_next;
	int		z_current;
	int		z_next;
	float	zoom;
	t_parse	*parsedata;
	t_coord	*coord;
}	t_mlx;

void	my_mlx_pixel_put_wu(t_mlx *mlx, int x, int y, int color);
void	line_put_wu(t_mlx *mlx, t_coord *coord);
void	map_processing(t_mlx *mlx);
void	map_to_image_peaks(t_mlx *mlx);

void	change_zoom(t_mlx *mlx, int *x, int *y);
int		screen_mut_isom(t_mlx *mlx, int value1, int value2, char x_or_y);
void	test_grid_put_square_wu(t_mlx *mlx, int x, int y, int color);
void	test_grid_put(t_mlx *mlx);
void	test_image_border(t_mlx *mlx);

float	percent(int start, int end, int current);
int		get_color(t_mlx *mlx, int current_color, float percentage);
int		set_colors_for_point(t_mlx *mlx);

float	ipart(float v1);
float	fpart(float v1);
float	rfpart(float v1);
void	swap(int *v1, int *v2);
char	abs_wu(int x_start, int y_start, int x_end, int y_end);

int		key_events(int key_code, t_mlx *mlx);

void	info_color_gradient(t_mlx *mlx);
void	put_menu(t_mlx *mlx);
char	*ft_itoa(float n, int multiplier);

void	swap_coord(t_coord *coord);
void	map_processing(t_mlx *mlx);
void	set_coord_and_draw_line(t_mlx *mlx, t_coord *coord);

#endif /*FDF_H*/
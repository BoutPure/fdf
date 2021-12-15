/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:54:13 by vseel             #+#    #+#             */
/*   Updated: 2021/12/13 17:30:50 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_color_and_put_pixel_y(t_mlx *mlx, int xpx11,
	int xpx12, int *pixel_color)
{
	float	percentage;

	percentage = percent(mlx->coord->x_start, mlx->coord->x_end, xpx11);
	*pixel_color = ((unsigned int)(rfpart(mlx->coord->intery) * 255) << 24)
		+ get_color(mlx, *pixel_color, percentage);
	my_mlx_pixel_put_wu(mlx, ipart(mlx->coord->intery), xpx11, *pixel_color);
	*pixel_color = ((unsigned int)(fpart(mlx->coord->intery) * 255) << 24)
		+ get_color(mlx, *pixel_color, percentage);
	my_mlx_pixel_put_wu(mlx, ipart(mlx->coord->intery) - 1, xpx11,
		*pixel_color);
	if (xpx12 < xpx11)
		mlx->coord->intery -= mlx->coord->gradient;
	else
		mlx->coord->intery += mlx->coord->gradient;
}

void	calc_color_and_put_pixel_n(t_mlx *mlx, int xpx11,
	int xpx12, int *pixel_color)
{
	float	percentage;

	percentage = percent(mlx->coord->x_start, mlx->coord->x_end, xpx11);
	*pixel_color = ((unsigned int)(rfpart(mlx->coord->intery) * 255) << 24)
		+ get_color(mlx, *pixel_color, percentage);
	my_mlx_pixel_put_wu(mlx, xpx11, ipart(mlx->coord->intery), *pixel_color);
	*pixel_color = ((unsigned int)(fpart(mlx->coord->intery) * 255) << 24)
		+ get_color(mlx, *pixel_color, percentage);
	my_mlx_pixel_put_wu(mlx, xpx11, ipart(mlx->coord->intery) - 1,
		*pixel_color);
	if (xpx12 < xpx11)
		mlx->coord->intery -= mlx->coord->gradient;
	else
		mlx->coord->intery += mlx->coord->gradient;
}

void	main_cycle(t_mlx *mlx, int xpx11, int *pixel_color, char steep)
{
	if (mlx->coord->x_end < xpx11 && steep == 'y')
		while (xpx11 >= mlx->coord->x_end)
			calc_color_and_put_pixel_y(mlx, xpx11--,
				mlx->coord->x_end, pixel_color);
	else if (steep == 'y')
		while (xpx11 <= mlx->coord->x_end)
			calc_color_and_put_pixel_y(mlx, xpx11++,
				mlx->coord->x_end, pixel_color);
	if (mlx->coord->x_end < xpx11 && steep == 'n')
		while (xpx11 >= mlx->coord->x_end)
			calc_color_and_put_pixel_n(mlx, xpx11--,
				mlx->coord->x_end, pixel_color);
	else if (steep == 'n')
		while (xpx11 <= mlx->coord->x_end)
			calc_color_and_put_pixel_n(mlx, xpx11++,
				mlx->coord->x_end, pixel_color);
}

void	line_put_wu(t_mlx *mlx, t_coord *coord)
{
	char	steep;
	int		xpx11;
	int		xpx12;
	int		pixel_color;

	change_zoom(mlx, &coord->x_start, &coord->y_start);
	change_zoom(mlx, &coord->x_end, &coord->y_end);
	steep = abs_wu(coord->x_start, coord->y_start, coord->x_end, coord->y_end);
	if (steep == 'y')
		swap_coord(coord);
	coord->gradient = (float)(coord->y_end - coord->y_start)
		/ (float)(coord->x_end - coord->x_start);
	if (coord->x_end - coord->x_start == 0)
		coord->gradient = 1.0;
	xpx11 = coord->x_start;
	xpx12 = coord->x_end;
	coord->intery = coord->y_start;
	pixel_color = set_colors_for_point(mlx);
	mlx->coord = coord;
	main_cycle(mlx, xpx11, &pixel_color, steep);
}

void	set_coord_and_draw_line(t_mlx *mlx, t_coord *coord)
{
	coord->x_s = screen_mut_isom(mlx, coord->x, coord->y, 'x');
	coord->y_s = screen_mut_isom(mlx, coord->y, coord->x, 'y');
	coord->x_s_next_elem = screen_mut_isom(mlx, coord->x + 1, coord->y, 'x');
	coord->x_s_next_line = screen_mut_isom(mlx, coord->x - 1, coord->y, 'x');
	coord->y_s_next_elem = screen_mut_isom(mlx, coord->y + 1, coord->x, 'y');
	coord->y_s_next_line = screen_mut_isom(mlx, coord->y + 1, coord->x, 'y');
	mlx->z_current = mlx->parsedata->z_val_arr[coord->x] * mlx->scale_z;
	mlx->z_next = mlx->parsedata->z_val_arr[coord->x + 1] * mlx->scale_z;
	coord->x_start = coord->x_s;
	coord->y_start = coord->y_s - mlx->z_current;
	coord->x_end = coord->x_s_next_elem;
	coord->y_end = coord->y_s_next_elem - mlx->z_next;
	if (coord->x <= mlx->parsedata->num_count - 2)
		line_put_wu(mlx, coord);
	if (mlx->parsedata->next)
	{
		mlx->z_next = mlx->parsedata->next->z_val_arr[coord->x] * mlx->scale_z;
		coord->x_start = coord->x_s;
		coord->y_start = coord->y_s - mlx->z_current;
		coord->x_end = coord->x_s_next_line;
		coord->y_end = coord->y_s_next_line - mlx->z_next;
		line_put_wu(mlx, coord);
	}
}

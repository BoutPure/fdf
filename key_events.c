/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:58:05 by vseel             #+#    #+#             */
/*   Updated: 2021/12/13 21:35:28 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_free_n_create_new(t_mlx *mlx)
{
	int	y;

	y = 0;
	free(mlx->img);
	free(mlx->addr);
	mlx->img = mlx_new_image(mlx->mlx_ptr, mlx->win_width, mlx->win_height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
}

void	key_change_scales_and_bias(int key_code, t_mlx *mlx)
{
	if (key_code == 13)
		mlx->scale_y -= 5;
	if (key_code == 0)
		mlx->scale_x -= 5;
	if (key_code == 1)
		mlx->scale_y += 5;
	if (key_code == 2)
		mlx->scale_x += 5;
	if (key_code == 5)
		mlx->scale_z += 2;
	if (key_code == 3)
		mlx->scale_z -= 2;
	if (key_code == 123)
		mlx->bias_x -= 1 + 10 / mlx->zoom;
	if (key_code == 124)
		mlx->bias_x += 1 + 10 / mlx->zoom;
	if (key_code == 125)
		mlx->bias_y += 1 + 10 / mlx->zoom;
	if (key_code == 126)
		mlx->bias_y -= 1 + 10 / mlx->zoom;
}

void	key_change_zoom(int key_code, t_mlx *mlx)
{
	if (key_code == 27 || key_code == 78)
	{
		if (mlx->zoom > 1)
			mlx->zoom -= 0.5;
		else if (mlx->zoom > 0.21)
			mlx->zoom -= 0.2;
		else
			mlx->zoom -= 0.01;
	}
	if (key_code == 24 || key_code == 69)
	{
		if (mlx->zoom > 1)
			mlx->zoom += 0.5;
		else if (mlx->zoom > 0.21)
			mlx->zoom += 0.2;
		else
			mlx->zoom += 0.01;
	}
}

int	key_events(int key_code, t_mlx *mlx)
{
	if (key_code == 53)
		exit(3);
	key_change_scales_and_bias(key_code, mlx);
	key_change_zoom(key_code, mlx);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	img_free_n_create_new(mlx);
	map_processing(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	put_menu(mlx);
	return (0);
}

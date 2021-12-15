/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:54:18 by vseel             #+#    #+#             */
/*   Updated: 2021/12/13 21:10:08 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_zoom(t_mlx *mlx, int *x, int *y)
{
	int	x0;
	int	y0;

	if (mlx->zoom < 0)
		mlx->zoom = 0;
	x0 = mlx->win_width / 2;
	y0 = mlx->win_height / 2;
	*x = x0 + (*x - x0) * mlx->zoom;
	*y = y0 + (*y - y0) * mlx->zoom;
}

int	screen_mut_isom(t_mlx *mlx, int value1, int value2, char x_or_y)
{
	if (x_or_y == 'x')
		value1 = ((value1 - value2) * mlx->scale_x) + mlx->bias_x;
	else if (x_or_y == 'y')
	{
		value1 = ((value1 + value2) * mlx->scale_y) + mlx->bias_y;
	}
	return (value1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:54:13 by vseel             #+#    #+#             */
/*   Updated: 2021/12/14 17:47:03 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	percent(int start, int end, int current)
{
	float	placement;
	float	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_mlx *mlx, int current_color, float percentage)
{
	int	red;
	int	green;
	int	blue;

	if (current_color == mlx->color_next)
		return (current_color);
	red = get_light((mlx->color_this >> 16) & 0xFF,
			(mlx->color_next >> 16) & 0xFF, percentage);
	green = get_light((mlx->color_this >> 8) & 0xFF,
			(mlx->color_next >> 8) & 0xFF, percentage);
	blue = get_light(mlx->color_this & 0xFF,
			mlx->color_next & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int	set_colors_for_point(t_mlx *mlx)
{
	if (mlx->z_current > 0)
		mlx->color_this = mlx->color_high;
	else if (mlx->z_current < 0)
		mlx->color_this = mlx->color_low;
	else
		mlx->color_this = mlx->color_flat;
	if (mlx->z_next > 0)
		mlx->color_next = mlx->color_high;
	else if (mlx->z_next < 0)
		mlx->color_next = mlx->color_low;
	else
		mlx->color_next = mlx->color_flat;
	return (mlx->color_flat);
}

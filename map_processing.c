/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:54:13 by vseel             #+#    #+#             */
/*   Updated: 2021/12/13 19:51:54 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put_wu(t_mlx *mlx, int x, int y, int color)
{
	char			*dst;

	if (x >= mlx->win_width || x < 0)
		return ;
	if (y >= mlx->win_height || y < 0)
		return ;
	dst = mlx->addr + (y * mlx->size_line + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	map_processing(t_mlx *mlx)
{
	t_coord	coord;
	t_parse	*temp;

	coord.y = 0;
	temp = mlx->parsedata;
	while (mlx->parsedata)
	{
		coord.x = 0;
		while (coord.x <= mlx->parsedata->num_count - 1)
		{
			set_coord_and_draw_line(mlx, &coord);
			coord.x++;
		}
		coord.y++;
		mlx->parsedata = mlx->parsedata->next;
	}
	mlx->parsedata = temp;
}

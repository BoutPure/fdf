/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:54:18 by vseel             #+#    #+#             */
/*   Updated: 2021/12/13 19:54:47 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ipart(float v1)
{
	return ((float)floor((double)v1));
}

float	fpart(float v1)
{
	return (v1 - (float)floor((double)v1));
}

float	rfpart(float v1)
{
	return (1 - fpart(v1));
}

void	swap_coord(t_coord *coord)
{
	int	temp;

	temp = coord->x_start;
	coord->x_start = coord->y_start;
	coord->y_start = temp;
	temp = coord->x_end;
	coord->x_end = coord->y_end;
	coord->y_end = temp;
}

char	abs_wu(int x_start, int y_start, int x_end, int y_end)
{
	int	x_abs;
	int	y_abs;

	x_abs = x_end - x_start;
	y_abs = y_end - y_start;
	if (x_abs < 0)
		x_abs *= -1;
	if (y_abs < 0)
		y_abs *= -1;
	if (y_abs > x_abs)
		return ('y');
	return ('n');
}

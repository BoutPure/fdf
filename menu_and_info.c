/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_and_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:54:18 by vseel             #+#    #+#             */
/*   Updated: 2021/12/12 20:49:11 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_params(t_mlx *mlx)
{
	char	*menu;

	menu = ft_itoa(mlx->scale_x, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 55 + 100, 10, 0x00FFFFFF, menu);
	free(menu);
	menu = ft_itoa(mlx->scale_y, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 55 + 100, 30, 0x00FFFFFF, menu);
	free(menu);
	menu = ft_itoa(mlx->scale_z, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 55 + 100, 50, 0x00FFFFFF, menu);
	free(menu);
	menu = ft_itoa(mlx->bias_x, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 55 + 100, 70, 0x00FFFFFF, menu);
	free(menu);
	menu = ft_itoa(mlx->bias_y, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 55 + 100, 90, 0x00FFFFFF, menu);
	free(menu);
	menu = ft_itoa(mlx->zoom, 2);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 55 + 100, 110, 0x00FFFFFF, menu);
	free(menu);
}

void	put_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 65, 10, 0xFFFFFF, "Scale X:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 65, 30, 0xFFFFFF, "Scale Y:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 65, 50, 0xFFFFFF, "Scale Z:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0x00db908a, "(A/D)");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 30, 0x00db908a, "(W/S)");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 50, 0x00db908a, "(F/G)");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 65, 70, 0xFFFFFF, "Bias X:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 65, 90, 0xFFFFFF, "Bias Y:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 70, 0x00db908a, "(</>)");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 90, 0x00db908a, "(^/v)");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 65, 110, 0xFFFFFF, "Zoom:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 110, 0x00db908a, "(+/-)");
	put_params(mlx);
}

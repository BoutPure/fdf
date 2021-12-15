/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:35:18 by vseel             #+#    #+#             */
/*   Updated: 2021/12/14 12:03:26 by vseel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_mlx *mlx)
{
	mlx->win_height = 700;
	mlx->win_width = 700;
	mlx->scale_x = 20;
	mlx->scale_y = 10;
	mlx->scale_z = 6;
	mlx->bias_y = mlx->win_height / 2;
	mlx->bias_x = mlx->win_width / 2;
	mlx->bias_x = (mlx->win_width - ft_lstsize(mlx->parsedata)
			* mlx->scale_x) / 3;
	mlx->bias_y = (mlx->win_height - mlx->parsedata->num_count
			* mlx->scale_y) / 3;
	if (ft_lstsize(mlx->parsedata) > mlx->parsedata->num_count)
		mlx->bias_x = (mlx->win_width + ft_lstsize(mlx->parsedata)
				* mlx->scale_x) / 3;
	mlx->zoom = 1;
	mlx->color_flat = 0x00FFFFFF;
	mlx->color_high = 0x00FF4040;
	mlx->color_low = 0x004040FF;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_width,
			mlx->win_height, "fdf");
	mlx->img = mlx_new_image(mlx->mlx_ptr, mlx->win_width, mlx->win_height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argc;
	if (!argv[1])
		ft_error_exit("Where is the map, dude?\n", 0);
	if (argc > 2)
		ft_putstr("This programm supports only one first map when executed\n");
	mlx.parsedata = ft_map_parser(argv[1]);
	set_default(&mlx);
	map_processing(&mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img, 0, 0);
	put_menu(&mlx);
	mlx_key_hook(mlx.win_ptr, key_events, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}

	// /*
	// * Tester of parsed map.
	// */
	// int i;
	// int j;
	// t_parse *temp;
	// temp = mlx.parsedata;
	// j = 1;
	// while (temp)
	// {
	// 	i = 0;
	// 	printf("%2d line: (%d) |", j, temp->num_count);
	// 	while (i < temp->num_count)
	// 		printf("%3d|", temp->z_val_arr[i++]);
	// 	printf("\n");
	// 	temp = temp->next;
	// 	j++;
	// }
	// printf("---end of map---\n");
	// /**/
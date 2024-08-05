/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:50:21 by htharrau          #+#    #+#             */
/*   Updated: 2024/08/05 14:53:46 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	init_data(t_data *data, char *argv1)
{
	srand(time(NULL));
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->map = NULL;
	data->map_name = argv1;
	data->x_max = 0;
	data->y_max = 0;
	data->offset_u = 300;
	data->offset_v = 300;
	data->zoom = 10;
	data->angle = 30;
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
	data->color_background = generate_random_light_color();
	data->color_panel = generate_random_light_color();
	data->color_fdf = generate_random_dark_color();
	data->img.width = 1300;
	data->img.height = 800;
	data->img.img = NULL;
	data->img.addr = NULL;
	data->img.bpp = 0;
	data->img.line_length = 0;
	data->img.endian = 0;
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		handle_error("Error initializing MLX", data);
	data->mlx_win = mlx_new_window(data->mlx, data->img.width, 
			data->img.height, data->map_name);
	if (!data->mlx_win)
		handle_error("Error creating window", data);
	data->img.img = mlx_new_image(data->mlx, data->img.width, data->img.height);
	if (!data->img.img)
		handle_error("Error creating image", data);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_length, &data->img.endian);
	if (!data->img.addr)
		handle_error("Error getting image address", data);
}

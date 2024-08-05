/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_key.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:29:26 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/31 18:18:03 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	key_press(int keycode, t_data *data)
{
	printf("Keycode pressed: %d\n", keycode);
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 65361 || keycode == 65363 || keycode == 65362 
		|| keycode == 65364)
		translation_press(keycode, data);
	else if (keycode == 65451 || keycode == 65453)
		zoom_press(keycode, data);
	else if (keycode == 65429 || keycode == 65431 || keycode == 65430 
		|| keycode == 65437 || keycode == 65436 || keycode == 65433 
		|| keycode == 114)
		rotation_press(keycode, data);
	update_display(data);
	return (0);
}

void	update_display(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, data->img.width, data->img.height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, 
			&data->img.line_length, &data->img.endian);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	panel(data);
}

void	zoom_press(int keycode, t_data *data)
{
	if (keycode == 65451)
	{
		if ((data->zoom) > 10)
			data->zoom *= 1.1;
		else 
			data->zoom += 1;
		data->offset_u -= (data->x_max) * data->zoom / 30;
		data->offset_v -= (data->y_max) * data->zoom / 30;
	}
	else if (keycode == 65453)
	{
		data->zoom /= 1.1;
		data->offset_u += (data->x_max) * data->zoom / 30;
		data->offset_v += (data->y_max) * data->zoom / 30;
	}
}

void	translation_press(int keycode, t_data *data)
{
	if (keycode == 65361)
		data->offset_u -= 50;
	else if (keycode == 65363)
		data->offset_u += 50;
	else if (keycode == 65362)
		data->offset_v -= 50;
	else if (keycode == 65364)
		data->offset_v += 50;
}

void	rotation_press(int keycode, t_data *data)
{
	if (keycode == 114)
		data->angle += 5;
	else if (keycode == 65429)
		data->angle_x = (data->angle_x - 5) % 360;
	else if (keycode == 65431)
		data->angle_x = (data->angle_x + 5) % 360;
	else if (keycode == 65430)
		data->angle_y = (data->angle_y - 5) % 360;
	else if (keycode == 65437)
		data->angle_y = (data->angle_y + 5) % 360;
	else if (keycode == 65436)
		data->angle_z = (data->angle_z - 5) % 360;
	else if (keycode == 65433)
		data->angle_z = (data->angle_z + 5) % 360;
}

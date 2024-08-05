/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_panel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:17:11 by htharrau          #+#    #+#             */
/*   Updated: 2024/08/05 16:09:06 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

// draw_rectangle(&data->img, data->color_panel);
void	panel(t_data *data)
{
	int	col;

	col = 0x000000;
	mlx_string_put(data->mlx, data->mlx_win, 47, 55, col, " / _|  | |/ _|");
	mlx_string_put(data->mlx, data->mlx_win, 47, 65, col, "| |_ __| | |_ ");
	mlx_string_put(data->mlx, data->mlx_win, 47, 75, col, "|  _/ _` |  _|");
	mlx_string_put(data->mlx, data->mlx_win, 47, 85, col, "| || (_| | |  ");
	mlx_string_put(data->mlx, data->mlx_win, 47, 95, col, "|_| \\__,_|_|  ");
	mlx_string_put(data->mlx, data->mlx_win, 47, 130, col, "+, -    : zoom");
	mlx_string_put(data->mlx, data->mlx_win, 47, 150, col,
		"arrows  : translate");
	mlx_string_put(data->mlx, data->mlx_win, 47, 170, col, 
		"r       : iso angle rotation");
	mlx_string_put(data->mlx, data->mlx_win, 47, 190, col, 
		"7, 8    : x-axis rotation");
	mlx_string_put(data->mlx, data->mlx_win, 47, 210, col, 
		"4, 5    : y-axis rotation");
	mlx_string_put(data->mlx, data->mlx_win, 47, 230, col, 
		"1, 2    : z-axis rotation");
}

void	draw_grid(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y <= img->height)
	{
		x = 0;
		while (x <= img->width)
		{
			if (x % 50 == 0 || y % 50 == 0)
				my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_rectangle(t_img *img, int color)
{
	int	x;
	int	y;

	y = 25;
	while (y <= 245)
	{
		x = 28;
		while (x <= 245)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

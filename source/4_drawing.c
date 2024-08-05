/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_drawing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:05:41 by htharrau          #+#    #+#             */
/*   Updated: 2024/08/05 15:19:38 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

// drawing the pixels
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = NULL;
	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	transform_point(t_point *point, t_data *data)
{
	float	rad;
	float	pi;
	t_angle	coo;

	pi = 3.14159265358979323846f;
	rad = data->angle_x * pi / 180;
	coo.y_rot_x = point->y * cos(rad) - point->z * sin(rad);
	coo.z_rot_x = point->y * sin(rad) + point->z * cos(rad);
	rad = data->angle_y * pi / 180;
	coo.x_rot_y = point->x * cos(rad) + coo.z_rot_x * sin(rad);
	coo.z_rot_y = -point->x * sin(rad) + coo.z_rot_x * cos(rad);
	rad = data->angle_z * pi / 180;
	coo.x_rot_z = coo.x_rot_y * cos(rad) - coo.y_rot_x * sin(rad);
	coo.y_rot_z = coo.x_rot_y * sin(rad) + coo.y_rot_x * cos(rad);
	rad = data->angle * pi / 180;
	point->u = round((coo.x_rot_z - coo.y_rot_z) * cos(rad) * data->zoom 
			+ data->offset_u);
	point->v = round(((coo.x_rot_z + coo.y_rot_z) * sin(rad) 
				- coo.z_rot_y) * data->zoom + data->offset_v);
}

// fill background and draw lines
void	draw_map(t_data *data)
{
	int			x;
	int			y;
	t_point		p1;

	fill_background(&data->img, data->color_background);
	y = 0;
	while (y < data->y_max) 
	{
		x = 0;
		while (x < data->x_max) 
		{
			p1.x = x;
			p1.y = y;
			p1.z = data->map[x][y].altitude;
			p1.color = (p1.z - data->min_z) * data->map[x][y].color;
			transform_point(&p1, data);
			right_neighbour_line(data, p1, p1.color);
			bottom_neighbour_line(data, p1, p1.color);
			x++;
		}
		y++;
	}
}

// Draw line to the right neighbor
void	right_neighbour_line(t_data *data, t_point p1, int color)
{
	t_point	p2;

	if (p1.x < data->x_max - 1) 
	{
		p2.x = p1.x + 1;
		p2.y = p1.y;
		p2.z = data->map[p1.x + 1][p1.y].altitude;
		transform_point(&p2, data);
		draw_line(&data->img, p1, p2, color);
	}
}

// Draw line to the bottom neighbor
void	bottom_neighbour_line(t_data *data, t_point p1, int color)
{
	t_point	p2;

	if (p1.y < data->y_max - 1) 
	{
		p2.x = p1.x;
		p2.y = p1.y + 1;
		p2.z = data->map[p1.x][p1.y + 1].altitude;
		transform_point(&p2, data);
		draw_line(&data->img, p1, p2, color);
	}
}

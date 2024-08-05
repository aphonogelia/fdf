/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:46:57 by htharrau          #+#    #+#             */
/*   Updated: 2024/08/05 11:56:09 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		ft_printf("Error: incorrect syntax. Please enter one filename.\n");
		return (1);
	}
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		ft_printf("Memory allocation for data struct failed.\n");
		return (1);
	}
	init_data(data, argv[1]);
	init_mlx(data);
	map(argv[1], data);
	calculate_offset_zoom(data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	panel(data);
	mlx_hook(data->mlx_win, 17, 1L << 17, close_window, data);
	mlx_key_hook(data->mlx_win, key_press, data);
	mlx_loop(data->mlx);
	return (0);
}

/* int main(int argc, char **argv)
{
	t_data  data;
	t_point pointA = {1, 1, 0, 0, 0};
	t_point pointB = {3, 1, 0, 0, 0};
	t_point pointC = {3, 3, 0, 0, 0};
	t_point pointD = {1, 3, 0, 0, 0};
	t_point pointAp = {1, 1, 1, 0, 0};
	t_point pointBp = {3, 1, 1, 0, 0};
	t_point pointCp = {3, 3, 1, 0, 0};
	t_point pointDp = {1, 3, 1, 0, 0};
	t_point pointE = {2, 2, 5, 0, 0}; 
	int     color;
	int     background_color;

	if (argc != 2)
		ft_printf("error");
	init_data(&data);
	init_mlx(&data, 800, 600);
	color = create_rgb(255, 150, 0); // Red color for the line
	background_color = create_rgb(255, 255, 255); // White background
	fill_background(&data.img, background_color);
	draw_test_pattern(&data.img);
	printf("POINT A\n");
	transform_point(&pointA, data.zoom, data.offset_u, data.offset_v);
	printf("POINT B\n");
	transform_point(&pointB, data.zoom, data.offset_u, data.offset_v);
	printf("POINT C\n");
	transform_point(&pointC, data.zoom, data.offset_u, data.offset_v);
	printf("POINT D\n");
	transform_point(&pointD, data.zoom, data.offset_u, data.offset_v);
	printf("POINT E\n");
	transform_point(&pointE, data.zoom, data.offset_u, data.offset_v);
	printf("POINT Ap\n");
	transform_point(&pointAp, data.zoom, data.offset_u, data.offset_v);
	printf("POINT Bp\n");
	transform_point(&pointBp, data.zoom, data.offset_u, data.offset_v);
	printf("POINT Cp\n");
	transform_point(&pointCp, data.zoom, data.offset_u, data.offset_v);
	printf("POINT Dp\n");
	transform_point(&pointDp, data.zoom, data.offset_u, data.offset_v);
	draw_line(&data.img, pointA, pointB, color);
	draw_line(&data.img, pointAp, pointBp, color);
	draw_line(&data.img, pointA, pointAp, color);
	// draw_line(&data.img, pointA, pointE, color);
	draw_line(&data.img, pointB, pointC, color);
	draw_line(&data.img, pointBp, pointCp, color);
	draw_line(&data.img, pointB, pointBp, color);
	// draw_line(&data.img, pointB, pointE, color);
	draw_line(&data.img, pointC, pointD, color);
	draw_line(&data.img, pointCp, pointDp, color);
	draw_line(&data.img, pointC, pointCp, color);
	// draw_line(&data.img, pointD, pointE, color);
	draw_line(&data.img, pointD, pointA, color);
	draw_line(&data.img, pointDp, pointAp, color);
	draw_line(&data.img, pointD, pointDp, color);
	// draw_line(&data.img, pointD, pointE, color);
	
	create_map(argv[1], &data);
	// allocate_map(&data);
	// parse_map(argv[1], &data);
	// draw_map(&data, create_rgb(0, 255, 50));
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img, 0, 0);
	mlx_hook(data.mlx_win, 17, 1L << 17, close_window,  &data);
	mlx_loop(data.mlx);
	return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_close.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:39:16 by htharrau          #+#    #+#             */
/*   Updated: 2024/08/05 15:31:06 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	handle_error(char *error_message, t_data *data)
{
	ft_printf("%s\n", error_message);
	close_window(data);
	exit(1);
}

int	close_window_event(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	close_window(data);
	return (0);
}

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->img.img)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = NULL;
	}
	if (data->mlx_win)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		data->mlx_win = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
	if (data->map)
		free_map(data);
	free(data);
	ft_printf("Exiting program...\n");
	exit(0);
	return (0);
}

void	free_map(t_data *data)
{
	int	x;

	x = 0;
	if (data->map)
	{
		while (x < data->x_max)
			free(data->map[x++]);
		free(data->map);
		data->map = NULL;
	}
}

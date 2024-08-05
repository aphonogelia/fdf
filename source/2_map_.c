/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_map_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:23:57 by htharrau          #+#    #+#             */
/*   Updated: 2024/08/05 14:54:50 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	map(char *file_name, t_data *data)
{
	get_map_dimension(file_name, data);
	allocate_map(data);
	parse_map(file_name, data);
	return (0);
}

int	allocate_map(t_data *data)
{
	int	x;

	data->map = (t_map **)malloc(sizeof(t_map *) * data->x_max);
	if (data->map == NULL)
		handle_error("Error: Failed allocation.", data);
	x = 0;
	while (x < data->x_max)
	{
		data->map[x] = (t_map *)malloc(sizeof(t_map) * data->y_max);
		if (data->map[x] == NULL)
		{
			while (x > 0)
				free(data->map[--x]);
			free(data->map);
			handle_error("Error: Failed allocation.", data);
		}
		x++;
	}
	return (0);
}

static int	process_line_altcol(t_data *data, int y, int x, char **values)
{
	char	**val_color;

	val_color = ft_split(values[x], ',');
	if (val_color == NULL)
	{
		free(values[x]);
		return (1);
	}
	data->map[x][y].altitude = ft_atoi(val_color[0]);
	if (val_color[1])
		data->map[x][y].color = ft_atoi_hex(val_color[1]);
	else 
		data->map[x][y].color = data->color_fdf;
	free(val_color[0]);
	if (val_color[1])
		free(val_color[1]);
	free(val_color);
	return (0);
}

static int	process_line(char *line, t_data *data, int y)
{
	char	**values;
	int		x;

	values = ft_split(line, ' ');
	if (values == NULL)
		return (1);
	x = 0;
	while (x < data->x_max)
	{
		if (!values[x])
		{
			ft_printf("Error: NULL value at values[%d] for line: %s\n", x, line);
			free(values);
			return (1);
		}
		if (process_line_altcol(data, y, x, values) == 1)
		{
			free_split(values);
			return (1);
		}
		x++;
	}
	free_split(values);
	return (0);
}

int	parse_map(char *file_name, t_data *data)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		handle_error("Error opening file.", data);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		if (process_line(line, data, y) == 1) 
		{
			free(line);
			close(fd);
			handle_error("Error parsing the line.", data);
		}
		free(line);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

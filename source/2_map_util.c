/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_map_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:58:41 by htharrau          #+#    #+#             */
/*   Updated: 2024/08/01 17:33:04 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	count_elmts(char *line, char sep)
{
	int		elt;
	size_t	i;

	elt = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == sep)
			i++;
		if (line[i] && line[i] != sep)
			elt++;
		while (line[i] && line[i] != sep)
			i++;
	}
	return (elt);
}

int	ft_atoi_hex(const char *str)
{
	int	result;
	int	base;
	int	i;

	result = 0;
	i = 0;
	base = 1;
	while (str[i] != '\0')
		i++;
	i = i - 1;
	while (i >= 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
			result += (str[i] - '0') * base;
		else if (str[i] >= 'A' && str[i] <= 'F')
			result += (str[i] - 'A' + 10) * base;
		else if (str[i] >= 'a' && str[i] <= 'f')
			result += (str[i] - 'a' + 10) * base;
		base *= 16;
		i--;
	}
	return (result);
}

int	get_map_dimension(char *file_name, t_data *data)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		handle_error("Error opening file.", data);
	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (y == 0)
			data->x_max = count_elmts(line, ' ');
		free(line);
		y++;
		line = get_next_line(fd);
	}
	free(line);
	data->y_max = y;
	data->map_name = file_name;
	close(fd);
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

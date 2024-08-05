/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_offset_zoom_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:23:51 by htharrau          #+#    #+#             */
/*   Updated: 2024/08/05 15:17:53 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

// alloc for the linked list {u,v}
void	init_coord(t_liste **list, t_data *data)
{
	*list = (t_liste *)malloc(sizeof(t_liste));
	if (!*list)
		handle_error("Memory allocation failed", data);
	(*list)->head = NULL;
}

// 0.523599 = 30 degrees rad
void	list_coordinates(t_data *data, t_liste *list)
{
	int		x;
	int		y;
	t_node	*pt;

	if (!list)
		return ;
	y = 0;
	while (y < data->y_max) 
	{
		x = 0;
		while (x < data->x_max) 
		{
			pt = (t_node *)malloc(sizeof(t_node));
			if (!pt)
				handle_error("Memory allocation failed", data); 
			pt->z = data->map[x][y].altitude;
			pt->u = (x - y) * 0.8660254;
			pt->v = (x + y) * 0.5 - data->map[x][y].altitude;
			pt->next = NULL;
			add_node(list, pt);
			x++;
		}
		y++;
	}
}

void	print_list(t_liste *list)
{
	t_node	*current;

	current = list->head;
	while (current)
	{
		printf("Node: u = %d, v = %d\n", current->u, current->v);
		current = current->next;
	}
}

void	calculate_offset_zoom(t_data *data)
{
	int		height;
	int		width;
	int		scale_height;
	int		scale_width;
	t_liste	*list;

	init_coord(&list, data);
	list_coordinates(data, list);
	height = find_max_ord(list) - find_min_ord(list);
	width = find_max_abs(list) - find_min_abs(list);
	scale_height = 5;
	if (height != 0)
		scale_height = (data->img.height - 200) / height;
	scale_width = 5;
	if (width != 0)
		scale_width = (data->img.width - 200) / width;
	data->zoom = fmin(scale_width, scale_height);
	data->offset_u = (data->img.width - data->zoom * width) / 2 
		- data->zoom * find_min_abs(list);
	data->offset_v = (data->img.height - data->zoom * height) / 2 
		- data->zoom * find_min_ord(list);
	data->gradient = find_max_z(list) - find_min_z(list);
	data->min_z = find_min_z(list);
	free_list(list);
	free(list);
}

void	free_list(t_liste *list)
{
	t_node	*current;
	t_node	*next;

	if (!list)
		return ;
	current = list->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	list->head = NULL;
}

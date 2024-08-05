/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_utils_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:44:32 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/29 16:31:11 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	add_node(t_liste *list, t_node *new_node)
{
	t_node	*current;

	if (!list || !new_node)
		return ;
	if (!list->head)
	{
		list->head = new_node;
		new_node->next = NULL;
	}
	else
	{
		current = list->head;
		while (current->next)
			current = current->next;
		current->next = new_node;
		new_node->next = NULL;
	}
}

int	find_min_abs(t_liste *list)
{
	t_node	*current;
	t_node	*min;

	if (list->head == NULL)
		return (0);
	current = list->head;
	min = current;
	while (current)
	{
		if (current->u < min->u)
			min = current;
		current = current->next;
	}
	return (min->u);
}

int	find_max_abs(t_liste *list)
{
	t_node	*current;
	t_node	*max;

	if (list->head == NULL)
		return (0);
	current = list->head;
	max = current;
	while (current)
	{
		if (current->u > max->u)
			max = current;
		current = current->next;
	}
	return (max->u);
}

int	find_min_ord(t_liste *list)
{
	t_node	*current;
	t_node	*min;

	if (list->head == NULL)
		return (0);
	current = list->head;
	min = current;
	while (current)
	{
		if (current->v < min->v)
			min = current;
		current = current->next;
	}
	return (min->v);
}

int	find_max_ord(t_liste *list)
{
	t_node	*current;
	t_node	*max;

	if (list->head == NULL)
		return (0);
	current = list->head;
	max = current;
	while (current)
	{
		if (current->v > max->v)
			max = current;
		current = current->next;
	}
	return (max->v);
}

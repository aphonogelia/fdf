/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_colors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:22:44 by htharrau          #+#    #+#             */
/*   Updated: 2024/08/05 12:06:45 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//  create_rgb(255, 0, 0);		// Bright red
//  create_rgb(0, 255, 0);		// Bright green
//  create_rgb(0, 0, 255);		// Bright blue
//  create_rgb(255, 255, 0);	// Bright yellow
//  create_rgb(0, 255, 255);	// Bright cyan
//  create_rgb(255, 0, 255);	// Bright magenta
//  create_rgb(200, 200, 200);	// White

// 	srand(time(NULL));
//  rand()

void	fill_background(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

// A linear congruential generator (LCG) is an algorithm that 
// yields a sequence of pseudo-randomized numbers
/* int	lcg_rand(int seed)
{
	seed = 25;
	seed = (1103515245 * seed + 12345) % (1 << 31);
	return (seed);
} */

/* int	generate_spec_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
} */

/* int	generate_random_light_color(int seed)
{
	int	r;
	int	g;
	int	b;

	r = 128 + lcg_rand(seed) % 128;
	g = 128 + lcg_rand(seed) % 128;
	b = 128 + lcg_rand(seed) % 128;
	return ((r << 16) | (g << 8) | b);
} */

int	generate_random_light_color(void)
{
	int	r;
	int	g;
	int	b;

	r = 128 + rand() % 128;
	g = 128 + rand() % 128;
	b = 128 + rand() % 128;
	return ((r << 16) | (g << 8) | b);
}

int	generate_random_dark_color(void)
{
	int	r;
	int	g;
	int	b;

	r = rand() % 128;
	g = rand() % 128;
	b = rand() % 128;
	return ((r << 16) | (g << 8) | b);
}

int	find_min_z(t_liste *list)
{
	t_node	*current;
	t_node	*min;

	if (list->head == NULL)
		return (0);
	current = list->head;
	min = current;
	while (current)
	{
		if (current->z < min->z)
			min = current;
		current = current->next;
	}
	return (min->z);
}

int	find_max_z(t_liste *list)
{
	t_node	*current;
	t_node	*max;

	if (list->head == NULL)
		return (0);
	current = list->head;
	max = current;
	while (current)
	{
		if (current->z > max->z)
			max = current;
		current = current->next;
	}
	return (max->z);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_slopes_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:53:40 by htharrau          #+#    #+#             */
/*   Updated: 2024/08/05 12:24:40 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	swap_points(t_point *p1, t_point *p2)
{
	t_point	temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void	draw_line(t_img *img, t_point p1, t_point p2, int color)
{
	int	du;
	int	dv;

	if (p2.u < p1.u) 
		swap_points(&p1, &p2);
	du = abs(p2.u - p1.u);
	dv = abs(p2.v - p1.v);
	if (du == 0 && dv == 0)
		my_mlx_pixel_put(img, p1.u, p1.v, color);
	else if (du == 0) 
		vertical_line(img, p1, p2, color);
	else if (dv == 0) 
		horizontal_line(img, p1, p2, color);
	else if (du >= dv && p1.v < p2.v)
		small_slope_pos(img, p1, p2, color);
	else if (du >= dv && p1.v > p2.v)
		small_slope_neg(img, p1, p2, color);
	else if (du < dv && p1.v < p2.v)
		big_slope_pos(img, p1, p2, color);
	else if (du < dv && p1.v > p2.v)
		big_slope_neg(img, p1, p2, color);
}

void	vertical_line(t_img *img, t_point p1, t_point p2, int color)
{
	int	u;
	int	v;
	int	dv;
	int	s;

	u = p1.u;
	v = p1.v;
	dv = p2.v - p1.v;
	if (dv < 0)
		s = -1;
	else
		s = 1;
	my_mlx_pixel_put(img, u, v, color);
	while (v != p2.v) 
	{
		v = v + s;
		my_mlx_pixel_put(img, u, v, color);
	}
}

void	horizontal_line(t_img *img, t_point p1, t_point p2, int color)
{
	int	u;
	int	v;

	u = p1.u;
	v = p1.v;
	my_mlx_pixel_put(img, u, v, color);
	while (u != p2.u) 
	{
		u = u + 1;
		my_mlx_pixel_put(img, u, v, color);
	}
}

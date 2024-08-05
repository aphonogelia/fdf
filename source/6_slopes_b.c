/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_slopes_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:36:18 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/26 14:52:26 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

// LINES

void	small_slope_pos(t_img *img, t_point p1, t_point p2, int color)
{
	int	du;
	int	dv;
	int	d;
	int	u;
	int	v;

	du = p2.u - p1.u;
	dv = p2.v - p1.v;
	d = 2 * dv - du;
	u = p1.u;
	v = p1.v;
	my_mlx_pixel_put(img, u, v, color);
	while (u != p2.u)
	{
		u = u + 1;
		if (d < 0)
			d = d + 2 * dv;
		else
		{
			v = v + 1;
			d = d + 2 * (dv - du);
		}
		my_mlx_pixel_put(img, u, v, color);
	}
}

void	small_slope_neg(t_img *img, t_point p1, t_point p2, int color)
{
	int	du;
	int	dv;
	int	d;
	int	u;
	int	v;

	du = p2.u - p1.u;
	dv = p1.v - p2.v;
	d = 2 * dv - du;
	u = p1.u;
	v = p1.v;
	my_mlx_pixel_put(img, u, v, color);
	while (u != p2.u)
	{
		u = u + 1;
		if (d < 0)
			d = d + 2 * dv;
		else
		{
			v = v - 1;
			d = d + 2 * (dv - du);
		}
		my_mlx_pixel_put(img, u, v, color);
	}
}

void	big_slope_pos(t_img *img, t_point p1, t_point p2, int color)
{
	int	du;
	int	dv;
	int	d;
	int	u;
	int	v;

	du = p2.u - p1.u;
	dv = p2.v - p1.v;
	d = 2 * du - dv;
	u = p1.u;
	v = p1.v;
	my_mlx_pixel_put(img, u, v, color);
	while (v != p2.v)
	{
		v = v + 1;
		if (d < 0)
			d = d + 2 * du;
		else
		{
			u = u + 1;
			d = d + 2 * (du - dv);
		}
		my_mlx_pixel_put(img, u, v, color);
	}
}

void	big_slope_neg(t_img *img, t_point p1, t_point p2, int color)
{
	int	du;
	int	dv;
	int	d;
	int	u;
	int	v;

	du = p2.u - p1.u;
	dv = p1.v - p2.v;
	d = 2 * du - dv;
	u = p1.u;
	v = p1.v;
	my_mlx_pixel_put(img, u, v, color);
	while (v != p2.v)
	{
		v = v - 1;
		if (d < 0)
			d = d + 2 * du;
		else
		{
			u = u + 1;
			d = d + 2 * (du - dv);
		}
		my_mlx_pixel_put(img, u, v, color);
	}
}

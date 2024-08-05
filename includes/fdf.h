/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:31:41 by htharrau          #+#    #+#             */
/*   Updated: 2024/08/05 15:17:31 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>
# include <linux/input-event-codes.h>
# include "../libft_pf_gnl/libft_pf_gnl.h"

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_angle {
	float	y_rot_x;
	float	z_rot_x;
	float	x_rot_z;
	float	y_rot_z;
	float	x_rot_y;
	float	z_rot_y;
}				t_angle;

typedef struct s_map {
	int		altitude;
	int		color;
}			t_map;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	char	*map_name;
	t_map	**map;
	int		x_max;
	int		y_max;
	int		offset_u;
	int		offset_v;
	int		zoom;
	int		angle;
	int		angle_x;
	int		angle_y;
	int		angle_z;
	int		color_background;
	int		color_panel;
	int		color_fdf;
	int		gradient;
	int		min_z;
}	t_data;

typedef struct s_point {
	int		x;
	int		y;
	int		z;
	int		u;
	int		v;
	int		color;
}			t_point;

typedef struct s_node {
	int				z;
	int				u;
	int				v;
	struct s_node	*next;
}			t_node;

typedef struct s_liste {
	t_node	*head;
}	t_liste;

// 0_MAIN

// 1_INIT
void	init_data(t_data *data, char *argv1);
void	init_mlx(t_data *data);

// 2_MAP
int		map(char *file_name, t_data *data);
int		get_map_dimension(char *file_name, t_data *data);
int		allocate_map(t_data *data);
int		parse_map(char *file_name, t_data *data);
void	free_split(char **split);
int		count_elmts(char *line, char sep);
int		ft_atoi_hex(const char *str);

// 3_OFFSET ZOOM
void	init_coord(t_liste **list, t_data *data);
void	list_coordinates(t_data *data, t_liste *list);
void	calculate_offset_zoom(t_data *data);
void	free_list(t_liste *list);
void	add_node(t_liste *list, t_node *new_node);
int		find_min_abs(t_liste *list);
int		find_max_abs(t_liste *list);
int		find_min_ord(t_liste *list);
int		find_max_ord(t_liste *list);

// 4_DRAWING TRANSFORMATION
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	transform_point(t_point *point, t_data *data);
void	draw_map(t_data *data);
void	right_neighbour_line(t_data *data, t_point p1, int color);
void	bottom_neighbour_line(t_data *data, t_point p1, int color);

// 5_COLORS Color handling functions
// int		lcg_rand(int seed);
void	fill_background(t_img *img, int color);
// int		generate_spec_color(int r, int g, int b);
int		generate_random_light_color(void);
int		generate_random_dark_color(void);
int		find_min_z(t_liste *list);
int		find_max_z(t_liste *list);

// 6_SLOPES Line drawing functions
void	draw_line(t_img *img, t_point p1, t_point p2, int color);
void	vertical_line(t_img *img, t_point p1, t_point p2, int color);
void	horizontal_line(t_img *img, t_point p1, t_point p2, int color);
void	small_slope_pos(t_img *img, t_point p1, t_point p2, int color);
void	small_slope_neg(t_img *img, t_point p1, t_point p2, int color);
void	big_slope_pos(t_img *img, t_point p1, t_point p2, int color);
void	big_slope_neg(t_img *img, t_point p1, t_point p2, int color);

// 7_KEYS
int		key_press(int keycode, t_data *data);
void	update_display(t_data *data);
void	zoom_press(int keycode, t_data *data);
void	translation_press(int keycode, t_data *data);
void	rotation_press(int keycode, t_data *data);

// 8_PANEL
void	draw_grid(t_img *img, int color);
void	draw_rectangle(t_img *img, int color);
void	panel(t_data *data);

// 9_CLEAN AND CLOSE
int		close_window(void *param);
int		close_window_event(void *param);
void	handle_error(char *error_message, t_data *data);
void	free_map(t_data *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:21:08 by sayari            #+#    #+#             */
/*   Updated: 2021/11/02 17:01:39 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "../GNL/get_next_line.h"
# define PI 3.14159

typedef struct s_map
{
	int		fd;
	char	*line;
	int		len;
	int		type;
	int		no;
	int		so;
	int		ea;
	int		we;
	int		f;
	int		c;
	int		first_line;
	int		last_line;
	int		i;
	int		fd_test;
	char	**tab;
	int		size;
	char	d;
	int		len_n;
	int		len_b;
	int		len_nn;
	int		len_bb;
	int		size_case;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		i_width;
	int		i_height;
	void	*wall_n;
	void	*wall_s;
	void	*wall_e;
	void	*wall_w;
	char	*addr;
	int		*a_n;
	int		*a_s;
	int		*a_e;
	int		*a_w;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	char	*c_n;
	char	*c_s;
	char	*c_e;
	char	*c_w;
	int		*data;
}	t_mlx;

typedef struct s_game
{
	float	angle;	
	int		pos_x;
	int		pos_y;
	float	ppos_x;
	float	ppos_y;
	float	speed;
}	t_game;

typedef struct s_rays
{
	float	dx;
	float	dy;
	float	steps;
	int		i;
	int		j;
	float	offset_x;
	float	offset_y;
	float	a_y;
	float	a_x;
	float	b_x;
	float	a_y2;
	float	xa;
	float	ya;
	int		grid_x;
	int		grid_y;
	float	a;
	float	b;
	float	aa;
	float	bb;
	float	fov_angle;
	int		co;
	float	dir;
	float	x_rays;
	float	y_rays;
}	t_rays;

typedef struct s_plan
{
	float	h;
	float	w;
	float	c_h;
	float	c_w;
	float	to_p;
	float	fov;
	float	half_fov;
	float	offset_angle;
	float	slice_h;
	float	d_to_wall;
	float	col;
	float	height;
	float	begin;
	float	end;

}	t_plan;

typedef struct s_image
{
	int		bits_per_pixel_n;
	int		line_length_n;
	int		endian_n;
	int		bits_per_pixel_s;
	int		line_length_s;
	int		endian_s;
	int		bits_per_pixel_e;
	int		line_length_e;
	int		endian_e;
	int		bits_per_pixel_w;
	int		line_length_w;
	int		endian_w;
	int		tx;
	int		ty;
	int		index;
	int		i;
	float	x;
	float	y;
	int		color;
}	t_image;

typedef struct s_general
{
	t_mlx	mlx;
	t_map	m;
	t_game	game;
	t_rays	r;
	t_plan	plan;
	t_image	img;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	int		i;
	int		j;
}	t_general;

// Check_Arg
void	ft_putstr(char *s);
int		check_arg(char *av[], int ac);
int		ft_strstr(char *s1, char *s2);
void	err(int c);
void	err2(int c);
void	init_general(t_general *g, char *av[]);
// LIB
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_isspace(int c);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
char	*ft_strndup(char const *s, size_t n);
int		ft_atoi(const char *str);
// PARSING first part
void	parsing(t_general *g, char *av[]);
int		parsing_first(t_general *g, int ret);
void	check_first_part(t_general *g);
int		check_identifier(t_general *g);
int		its_empty_line(t_general *g);
void	close_and_free(t_general *g, char *texture, int c);
void	check_line_identifier(t_general *g);
void	check_valid_texture(char *texture, t_general *g);
void	check_valid_texture2(char *texture, t_general *g);
void	err_texture(int c, t_general *g);
void	check_ext_texture(char *texture);

int		check_color(t_general *g);
void	check_one_color(t_general *g);
void	check_line_color(t_general *g);
void	check_valid_color(char *color, t_general *g);
void	err_and_free(int c, char **str);
void	check_only_comma_and_int(char *str, int c);
void	check_color_floor(char **str, t_general *g);
void	check_color_cell(char **str, t_general *g);
void	free_color(char **color_tab, char *color);
int		check_after_type(t_general *g);

// PARSING second part
void	map_check_first(t_general *g);
int		is_valid_char(int c);
int		map_empty_line(char *line);
int		check_is_pos(t_general *g, char c);
int		check_is_pos2(t_general *g, char c);
void	check_pos(t_general *g);
void	check_map(t_general *g);
void	check_map2(t_general *g);
int		check_wall_line(char *line, t_general *g);
int		check_only_wall(char *line);
int		wall_height_r(int i, t_general *g);
int		wall_height_l(int i, t_general *g);
int		check_diff(int i, int j, t_general *g);
int		check_diff2(int i, int j, t_general *g);
int		check_r_diff(int i, int j, t_general *g);
int		check_r_diff2(int i, int j, t_general *g);
void	get_len(char *line, int c, t_general *g);
void	get_before_len(char *line, int c, t_general *g);
int		check_space(int i, t_general *g);
int		check_validity_space(int i, int j, t_general *g);

//Take_Map
void	take_the_map(t_general *g, char *av[]);
void	get_the_max_line(t_general *g, char *av[]);
void	fill_tab(t_general *g, char *av[]);
void	free_tab(t_general *g);
void	free_tab_m(int c, t_general *g);

//Draw
void	my_mlx_pixel_put(t_general *g, int x, int y, int color);
int		in_game(t_general *g);
void	map(t_general *g);
void	draw_map(t_general *g, int x, int y, int color);
void	draw_map_player(t_general *g, int x, int y, int color);
void	redisplay(t_general *g);
void	draw_line(t_general *g, float x2, float y2, int color);
void	good_distance(t_general *g);

//Find Walls
void	find_ax_ay(t_general *g, char c);
int		find_ya_xa(t_general *g, char c);
int		find_limit(t_general *g, char c);
int		find_limit_loop(t_general *g, char c);
void	check_horizontal(t_general *g);
void	check_verticale(t_general *g);

//Key
int		ft_key(int keycode, t_general *g);
int		close_win(t_general *g);

//Angle
void	start_angle(t_general *g);
float	to_angle(float angle);
float	to_rad(float angle);

//Move
void	move_forward(t_general *g);
void	move_backward(t_general *g);
void	move_right(t_general *g);
void	move_left(t_general *g);
void	r_pivot(t_general *g);
void	l_pivot(t_general *g);

void	display_slice(t_general *g);
int		convert(unsigned char r, unsigned char g, unsigned char b);
void	draw_wall_h(t_general *g);
void	draw_wall_v(t_general *g);
void	draw_loop(t_general *g);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:04:49 by sayari            #+#    #+#             */
/*   Updated: 2021/11/02 18:01:24 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	start_angle(t_general *g)
{
	if (g->m.d == 'N')
		g->game.angle = to_rad(90.0);
	if (g->m.d == 'E')
		g->game.angle = to_rad(0.0);
	if (g->m.d == 'S')
		g->game.angle = to_rad(270.0);
	if (g->m.d == 'W')
		g->game.angle = to_rad(180.0);
	g->m.size_case = 16.0;
	g->game.speed = 4.5;
	g->plan.w = 1920;
	g->plan.h = 1080;
	g->plan.c_h = g->plan.h / 2.0;
	g->plan.c_w = g->plan.w / 2.0;
	g->plan.fov = 60.0;
	g->plan.half_fov = g->plan.fov / 2.0;
	g->plan.to_p = g->plan.c_w / tanf(to_rad(g->plan.half_fov));
	g->plan.offset_angle = g->plan.fov / g->plan.w;
	g->plan.col = 0.0;
}

void	find_pix(t_general *g)
{
	if (g->r.co == 1)
		g->img.tx = fmod(g->img.y / g->m.size_case, 1.0) * 64.0;
	else if (g->r.co == 2)
		g->img.tx = fmod(g->img.x / g->m.size_case, 1.0) * 64.0;
	g->img.ty = (1.0 - (double)(g->plan.end - g->img.i)
			/ (double)g->plan.height) * (double)64.0;
	g->img.index = g->img.tx + (g->img.ty * 64.0);
}

void	display_slice(t_general *g)
{
	g->img.i = 0;
	g->plan.height = ceilf((g->m.size_case / g->plan.d_to_wall) * g->plan.to_p);
	g->plan.begin = g->plan.c_h - (g->plan.height / 2);
	g->plan.end = g->plan.begin + g->plan.height;
	while (g->img.i < g->plan.h)
	{
		if (g->img.i >= g->plan.begin && g->img.i <= g->plan.end)
		{
			find_pix(g);
			draw_wall_v(g);
			draw_wall_h(g);
		}
		else if (g->img.i < g->plan.begin)
			my_mlx_pixel_put(g, g->plan.col, g->img.i,
				convert(g->c_r, g->c_g, g->c_b));
		else if (g->img.i > g->plan.end)
			my_mlx_pixel_put(g, g->plan.col, g->img.i,
				convert(g->f_r, g->f_g, g->f_b));
		g->img.i++;
	}
}

int	in_game(t_general *g)
{
	int		i;

	i = 0;
	g->r.fov_angle = g->game.angle;
	g->plan.col = 1919.0;
	g->r.a = g->game.angle - to_rad(30.0);
	g->r.b = g->game.angle + to_rad(30.0);
	g->r.aa = g->r.a;
	g->r.bb = g->r.b;
	draw_loop(g);
	while (g->r.a < g->r.b)
	{
		g->game.angle = g->r.a;
		check_verticale(g);
		check_horizontal(g);
		good_distance(g);
		g->r.a += to_rad(g->plan.offset_angle);
		g->plan.col--;
	}
	g->game.angle = g->r.fov_angle;
	return (0);
}

void	good_distance(t_general *g)
{
	float	d1;
	float	d2;

	d1 = sqrtf(((g->game.ppos_x - g->r.a_x) * (g->game.ppos_x - g->r.a_x))
			+ ((g->game.ppos_y - g->r.a_y) * (g->game.ppos_y - g->r.a_y)));
	d2 = sqrtf(((g->game.ppos_x - g->r.b_x) * (g->game.ppos_x - g->r.b_x))
			+ ((g->game.ppos_y - g->r.a_y2) * (g->game.ppos_y - g->r.a_y2)));
	if (d1 > d2)
	{
		draw_line(g, g->r.b_x, g->r.a_y2, 0x0078D500);
		g->plan.d_to_wall = d2 * cos(g->game.angle - g->r.fov_angle);
		g->r.co = 1;
		g->img.x = g->r.b_x;
		g->img.y = g->r.a_y2;
	}
	else
	{
		draw_line(g, g->r.a_x, g->r.a_y, 0x0078D500);
		g->plan.d_to_wall = d1 * cos(g->game.angle - g->r.fov_angle);
		g->r.co = 2;
		g->img.x = g->r.a_x;
		g->img.y = g->r.a_y;
	}
}

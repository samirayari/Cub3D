/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 07:36:29 by sayari            #+#    #+#             */
/*   Updated: 2021/11/03 07:36:32 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_wall_v(t_general *g)
{
	if (g->r.co == 1)
	{
		if (cosf(g->game.angle) > 0)
		{
			g->img.color = g->mlx.a_e[g->img.index];
			my_mlx_pixel_put(g, g->plan.col, g->img.i, g->img.color);
		}
		else
		{
			g->img.color = g->mlx.a_w[g->img.index];
			my_mlx_pixel_put(g, g->plan.col, g->img.i, g->img.color);
		}
	}
}

void	draw_wall_h(t_general *g)
{
	if (g->r.co == 2)
	{
		if (sinf(g->game.angle) > 0)
		{
			g->img.color = g->mlx.a_n[g->img.index];
			my_mlx_pixel_put(g, g->plan.col, g->img.i, g->img.color);
		}
		else
		{
			g->img.color = g->mlx.a_s[g->img.index];
			my_mlx_pixel_put(g, g->plan.col, g->img.i, g->img.color);
		}
	}
}

void	draw_loop(t_general *g)
{
	while (g->r.a < g->r.b)
	{
		g->game.angle = g->r.a;
		check_verticale(g);
		check_horizontal(g);
		good_distance(g);
		display_slice(g);
		g->r.a += to_rad(g->plan.offset_angle);
		g->plan.col--;
	}	
	g->r.a = g->r.aa;
	g->r.b = g->r.bb;
	map(g);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:06:36 by sayari            #+#    #+#             */
/*   Updated: 2021/11/02 11:27:36 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_general *g, int x, int y, int color)
{
	char	*dst;

	dst = g->mlx.addr
		+ (y * g->mlx.line_length + x * (g->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_general *g, float x2, float y2, int color)
{
	float	x1;
	float	y1;

	x1 = g->game.ppos_x;
	y1 = g->game.ppos_y;
	g->r.i = 0;
	g->r.dx = x2 - x1;
	g->r.dy = y2 - y1;
	if (fabsf(g->r.dx) > fabsf(g->r.dy))
		g->r.steps = fabsf(g->r.dx);
	else
		g->r.steps = fabsf(g->r.dy);
	g->r.offset_x = g->r.dx / g->r.steps;
	g->r.offset_y = g->r.dy / g->r.steps;
	while (g->r.i <= g->r.steps)
	{
		my_mlx_pixel_put(g, floorf(x1), floorf(y1), color);
		x1 += g->r.offset_x;
		y1 += g->r.offset_y;
		g->r.i++;
	}
}

int	convert(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}

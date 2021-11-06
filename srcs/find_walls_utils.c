/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_walls_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:06:59 by sayari            #+#    #+#             */
/*   Updated: 2021/10/31 14:35:20 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	find_ax_ay(t_general *g, char c)
{
	g->r.j = 0;
	if (c == 'h')
	{
		if (sinf(g->game.angle) >= 0.0)
			g->r.a_y = floorf(g->game.ppos_y
					/ (g->m.size_case)) * (g->m.size_case) - 0.0001;
		else
			g->r.a_y = floorf(g->game.ppos_y
					/ (g->m.size_case)) * (g->m.size_case) + g->m.size_case;
		g->r.a_x = g->game.ppos_x
			+ (g->game.ppos_y - g->r.a_y) / tanf(g->game.angle);
	}
	else if (c == 'v')
	{
		if (cosf(g->game.angle) >= 0.0)
			g->r.b_x = floorf(g->game.ppos_x
					/ (g->m.size_case)) * (g->m.size_case) + g->m.size_case;
		else
			g->r.b_x = floorf(g->game.ppos_x
					/ (g->m.size_case)) * (g->m.size_case) - 0.0001;
		g->r.a_y2 = g->game.ppos_y
			+ (g->game.ppos_x - g->r.b_x) * tanf(g->game.angle);
	}
}

int	find_ya_xa(t_general *g, char c)
{
	if (c == 'h')
	{
		if (sinf(g->game.angle) > 0.0)
			g->r.ya = -g->m.size_case;
		else
			g->r.ya = g->m.size_case;
		if (tanf(g->game.angle) == 0.0)
			return (0);
		g->r.xa = g->m.size_case / tanf(g->game.angle);
	}
	if (c == 'v')
	{
		if (cosf(g->game.angle) > 0.0)
			g->r.xa = g->m.size_case;
		else
			g->r.xa = -g->m.size_case;
		g->r.ya = g->m.size_case * tanf(g->game.angle);
		if (!(sinf(g->game.angle) > 0.0) && cosf(g->game.angle) > 0.0)
			g->r.ya = -g->r.ya;
		if ((sinf(g->game.angle) > 0.0) && cosf(g->game.angle) > 0.0)
			g->r.ya = -g->r.ya;
	}
	return (1);
}

int	find_limit(t_general *g, char c)
{
	if (c == 'h')
	{
		g->r.grid_y = floorf(g->r.a_y) / g->m.size_case;
		g->r.grid_x = floorf(g->r.a_x) / g->m.size_case;
		if (g->r.grid_y > g->m.size - 1 || g->r.grid_y < 0 || g->r.grid_x < 0)
			return (0);
		if (g->r.grid_x > (int)ft_strlen(g->m.tab[g->r.grid_y]))
			return (0);
		if (g->m.tab[g->r.grid_y][g->r.grid_x] == '1')
			g->r.j = 1;
	}
	if (c == 'v')
	{
		if (g->r.grid_y > g->m.size - 1 || g->r.grid_y < 0 || g->r.grid_x < 0)
			return (0);
		if (g->r.grid_x > (int)ft_strlen(g->m.tab[g->r.grid_y]))
			return (0);
		if (g->m.tab[g->r.grid_y][g->r.grid_x] == '1')
			g->r.j = 1;
	}
	return (1);
}

int	find_limit_loop(t_general *g, char c)
{
	if (c == 'h')
	{
		g->r.grid_y = floorf(g->r.a_y) / g->m.size_case;
		g->r.grid_x = floorf(g->r.a_x) / g->m.size_case;
		if (g->r.grid_y > g->m.size - 1 || g->r.grid_y < 0 || g->r.grid_x < 0)
			return (0);
		if (g->r.grid_x > (int)ft_strlen(g->m.tab[g->r.grid_y]))
			return (0);
		if (g->r.a_y < 0.0 || g->r.a_x < 0.0 || g->r.a_x > 1920.0)
			return (0);
	}
	if (c == 'v')
	{
		g->r.grid_x = floorf(g->r.b_x) / g->m.size_case;
		g->r.grid_y = floorf(g->r.a_y2) / g->m.size_case;
		if (g->r.grid_y > g->m.size - 1 || g->r.grid_y < 0 || g->r.grid_x < 0)
			return (0);
		if (g->r.grid_x > (int)ft_strlen(g->m.tab[g->r.grid_y]))
			return (0);
	}
	return (1);
}

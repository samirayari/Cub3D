/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_start_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:08:39 by sayari            #+#    #+#             */
/*   Updated: 2021/10/31 14:33:36 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_horizontal(t_general *g)
{
	find_ax_ay(g, 'h');
	if (!find_ya_xa(g, 'h'))
		return ;
	if (!find_limit(g, 'h'))
		return ;
	if (!(cosf(g->game.angle) > 0.0) && !(sinf(g->game.angle) > 0.0))
		g->r.xa = -g->r.xa;
	if ((cosf(g->game.angle) > 0.0) && !(sinf(g->game.angle) > 0.0))
		g->r.xa = -g->r.xa;
	if (g->r.a_x < 0.0 || g->r.a_y < 0.0 || g->r.a_x > 1920.0)
		return ;
	while (g->r.j < 1)
	{
		if (!find_limit_loop(g, 'h'))
			return ;
		if (g->m.tab[g->r.grid_y][g->r.grid_x] == '1')
			break ;
		g->r.a_x += g->r.xa;
		g->r.a_y += g->r.ya;
	}
}

void	check_verticale(t_general *g)
{
	find_ax_ay(g, 'v');
	find_ya_xa(g, 'v');
	g->r.grid_y = floorf(g->r.a_y2) / g->m.size_case;
	g->r.grid_x = floorf(g->r.b_x) / g->m.size_case;
	if (!find_limit(g, 'v'))
		return ;
	while (g->r.j < 1)
	{
		g->r.b_x += g->r.xa;
		g->r.a_y2 += g->r.ya;
		if (!find_limit_loop(g, 'v'))
			return ;
		if (g->m.tab[g->r.grid_y][g->r.grid_x] == '1')
			break ;
		if (g->r.b_x > 1920.0 || g->r.a_y2 < 0.0
			|| g->r.a_y2 > 1080.0 || g->r.b_x < 0.0)
			return ;
	}
}

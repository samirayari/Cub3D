/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:07:12 by sayari            #+#    #+#             */
/*   Updated: 2021/10/30 17:37:47 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	to_rad(float angle)
{
	return (angle * (PI / 180));
}

float	to_angle(float angle)
{
	return (angle * 180 / PI);
}

void	redisplay(t_general *g)
{
	mlx_clear_window(g->mlx.mlx, g->mlx.win);
	in_game(g);
	mlx_put_image_to_window(g->mlx.mlx, g->mlx.win, g->mlx.img, 0, 0);
}

void	r_pivot(t_general *g)
{
	g->game.angle -= to_rad(3.0);
	if (g->game.angle <= 0.0)
		g->game.angle = to_rad(359.0);
	redisplay(g);
}

void	l_pivot(t_general *g)
{
	g->game.angle += to_rad(3.0);
	if (g->game.angle > to_rad(360.0))
		g->game.angle = to_rad(1.0);
	redisplay(g);
}

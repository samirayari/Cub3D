/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:15:30 by sayari            #+#    #+#             */
/*   Updated: 2021/10/31 11:23:20 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_key(int keycode, t_general *g)
{
	if (keycode == 13)
		move_forward(g);
	if (keycode == 0)
		move_left(g);
	if (keycode == 1)
		move_backward(g);
	if (keycode == 2)
		move_right(g);
	if (keycode == 53)
		close_win(g);
	if (keycode == 123)
		l_pivot(g);
	if (keycode == 124)
		r_pivot(g);
	return (0);
}

void	move_forward(t_general *g)
{
	float	x;
	float	y;
	int		case_x;
	int		case_y;

	x = cosf(g->game.angle) * g->game.speed;
	y = sinf(g->game.angle) * g->game.speed;
	case_x = (g->game.ppos_x + x) / g->m.size_case;
	case_y = (g->game.ppos_y - y) / g->m.size_case;
	if (g->m.tab[case_y][case_x] == '1')
		return ;
	g->game.ppos_x += x;
	g->game.ppos_y -= y;
	redisplay(g);
}

void	move_backward(t_general *g)
{
	float	x;
	float	y;
	int		case_x;
	int		case_y;

	x = cosf(g->game.angle) * g->game.speed;
	y = sinf(g->game.angle) * g->game.speed;
	case_x = (g->game.ppos_x - x) / g->m.size_case;
	case_y = (g->game.ppos_y + y) / g->m.size_case;
	if (g->m.tab[case_y][case_x] == '1')
		return ;
	g->game.ppos_x -= x;
	g->game.ppos_y += y;
	redisplay(g);
}

void	move_right(t_general *g)
{
	float	x;
	float	y;
	int		case_x;
	int		case_y;

	x = cosf(g->game.angle - to_rad(90.0)) * g->game.speed;
	y = sinf(g->game.angle - to_rad(90.0)) * g->game.speed;
	case_x = (g->game.ppos_x + x) / g->m.size_case;
	case_y = (g->game.ppos_y - y) / g->m.size_case;
	if (g->m.tab[case_y][case_x] == '1')
		return ;
	g->game.ppos_x += x;
	g->game.ppos_y -= y;
	redisplay(g);
}

void	move_left(t_general *g)
{
	float	x;
	float	y;
	int		case_x;
	int		case_y;

	x = cosf(g->game.angle + to_rad(90.0)) * g->game.speed;
	y = sinf(g->game.angle + to_rad(90.0)) * g->game.speed;
	case_x = (g->game.ppos_x + x) / g->m.size_case;
	case_y = (g->game.ppos_y - y) / g->m.size_case;
	if (g->m.tab[case_y][case_x] == '1')
		return ;
	g->game.ppos_x += x;
	g->game.ppos_y -= y;
	redisplay(g);
}

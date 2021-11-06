/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:32:34 by sayari            #+#    #+#             */
/*   Updated: 2021/11/02 11:27:32 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_win(t_general *g)
{
	int	i;

	i = 0;
	if (g->m.tab)
	{
		while (g->m.tab[i])
		{
			free(g->m.tab[i]);
			i++;
		}
		free(g->m.tab);
	}
	mlx_destroy_window(g->mlx.mlx, g->mlx.win);
	exit(1);
	return (0);
}

void	draw_map(t_general *g, int x, int y, int color)
{
	int	i;
	int	j;
	int	case_x;
	int	case_y;

	case_x = g->m.size_case * x;
	case_y = g->m.size_case * y;
	i = 0;
	while (i < g->m.size_case)
	{
		j = 0;
		while (j < g->m.size_case)
		{
			my_mlx_pixel_put(g, i + case_x, j + case_y, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_general *g, int x, int y, int color)
{
	int	case_x;
	int	case_y;
	int	half;

	color = 0;
	case_x = g->m.size_case * x;
	case_y = g->m.size_case * y;
	half = g->m.size_case / 2;
	g->game.ppos_x = case_x + half;
	g->game.ppos_y = case_y + half;
}

void	map(t_general *g)
{
	int			i;
	int			j;
	static int	k = 0;

	i = 0;
	while (i < g->m.size)
	{
		j = 0;
		while (j < (int)ft_strlen(g->m.tab[i]))
		{
			if (g->m.tab[i][j] == '1')
				draw_map(g, j, i, 0x00000000);
			else if (g->m.tab[i][j] == '0' || g->m.tab[i][j] != ' ')
			{
				draw_map(g, j, i, convert(g->f_r, g->f_g, g->f_b));
				if (k == 0 && j == g->game.pos_x && i == g->game.pos_y)
				{
					draw_player(g, j, i, 0x002FFC2);
					k++;
				}
			}
			j++;
		}
		i++;
	}
}

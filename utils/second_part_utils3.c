/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 08:32:39 by sayari            #+#    #+#             */
/*   Updated: 2021/09/22 08:07:45 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	wall_height_r(int i, t_general *g)
{
	int	size;

	get_len(g->m.tab[i - 1], 1, g);
	get_len(g->m.tab[i], 2, g);
	if (g->m.len_n > g->m.len_b)
	{
		size = g->m.len_n - g->m.len_b;
		if (!(check_diff(i, size, g)))
			return (0);
	}
	if (g->m.len_n < g->m.len_b)
	{
		size = g->m.len_b - g->m.len_n;
		if (!(check_diff2(i, size, g)))
			return (0);
	}
	return (1);
}

int	check_diff(int i, int j, t_general *g)
{
	while (j)
	{
		if (g->m.tab[i][g->m.len_b] != '1')
			return (0);
		g->m.len_b++;
		j--;
	}
	return (1);
}

int	check_diff2(int i, int j, t_general *g)
{
	while (j)
	{
		if (g->m.tab[i - 1][g->m.len_n] != '1')
			return (0);
		g->m.len_n++;
		j--;
	}
	return (1);
}

int	check_r_diff(int i, int j, t_general *g)
{
	g->m.len_bb++;
	while (g->m.len_bb < j)
	{
		if (g->m.tab[i - 1][g->m.len_bb] != '1')
			return (0);
		g->m.len_bb++;
	}
	return (1);
}

int	check_r_diff2(int i, int j, t_general *g)
{
	while (j)
	{
		if (g->m.tab[i][g->m.len_nn] != '1')
			return (0);
		g->m.len_nn++;
		j--;
	}
	return (1);
}

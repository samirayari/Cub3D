/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part_utils4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:50:01 by sayari            #+#    #+#             */
/*   Updated: 2021/09/22 10:16:42 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_before_len(char *line, int c, t_general *g)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (c == 1)
		g->m.len_bb = i;
	if (c == 2)
		g->m.len_nn = i;
}

int	wall_height_l(int i, t_general *g)
{
	int	size;

	get_before_len(g->m.tab[i - 1], 1, g);
	get_before_len(g->m.tab[i], 2, g);
	if (g->m.len_nn > g->m.len_bb)
	{
		size = g->m.len_nn - g->m.len_bb;
		if (!(check_r_diff(i, size, g)))
			return (0);
	}
	if (g->m.len_nn < g->m.len_bb)
	{
		size = g->m.len_bb - g->m.len_nn;
		if (!(check_r_diff2(i, size, g)))
			return (0);
	}
	return (1);
}

int	check_is_pos2(t_general *g, char c)
{
	(void)g;
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

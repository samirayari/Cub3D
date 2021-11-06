/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:32:30 by sayari            #+#    #+#             */
/*   Updated: 2021/09/22 10:36:27 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_validity_space(int i, int j, t_general *g)
{
	if (ft_strlen(g->m.tab[i]) < ft_strlen(g->m.tab[i - 1])
		&& g->m.tab[i - 1][j] == '0')
		return (0);
	if (ft_strlen(g->m.tab[i]) < ft_strlen(g->m.tab[i + 1])
		&& g->m.tab[i + 1][j] == '0')
		return (0);
	if (j > 0 && g->m.tab[i][j - 1] == '0')
		return (0);
	if (g->m.tab[i][j + 1] == '0')
		return (0);
	if (ft_strlen(g->m.tab[i]) < ft_strlen(g->m.tab[i - 1])
		&& check_is_pos2(g, g->m.tab[i - 1][j]))
		return (0);
	if (ft_strlen(g->m.tab[i]) < ft_strlen(g->m.tab[i + 1])
		&& check_is_pos2(g, g->m.tab[i + 1][j]))
		return (0);
	if (j > 0 && check_is_pos2(g, g->m.tab[i][j - 1]))
		return (0);
	if (check_is_pos2(g, g->m.tab[i][j + 1]))
		return (0);
	return (1);
}

int	check_space(int i, t_general *g)
{
	int	j;

	j = 0;
	while (g->m.tab[i][j])
	{
		if (g->m.tab[i][j] == ' ')
		{
			if (check_validity_space(i, j, g) == 0)
				return (0);
		}
		j++;
	}
	return (1);
}

void	check_map2(t_general *g)
{
	if (g->i > 0 && g->i < (g->m.size - 1))
		if ((wall_height_l(g->i, g)) == 0)
			free_tab_m(2, g);
	if (g->i == (g->m.size - 1))
		if ((wall_height_l(g->i, g)) == 0)
			free_tab_m(2, g);
	if (g->i > 0 && g->i < (g->m.size - 1))
		if ((check_space(g->i, g)) == 0)
			free_tab_m(3, g);
}

void	check_map(t_general *g)
{
	get_len(g->m.tab[g->i], g->m.len_b, g);
	get_before_len(g->m.tab[g->i], g->m.len_bb, g);
	while (g->m.tab[g->i])
	{
		if (g->i == 0 || g->i == (g->m.size - 1))
			if (check_only_wall(g->m.tab[g->i]) == 0)
				free_tab_m(1, g);
		if (check_wall_line(g->m.tab[g->i], g) == 0)
			free_tab_m(1, g);
		if (g->i > 0 && g->i < (g->m.size - 1))
			if ((wall_height_r(g->i, g)) == 0)
				free_tab_m(2, g);
		if (g->i == (g->m.size - 1))
			if ((wall_height_r(g->i, g)) == 0)
				free_tab_m(2, g);
		check_map2(g);
		g->i++;
	}
}

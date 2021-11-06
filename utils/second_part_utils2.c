/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:26:29 by sayari            #+#    #+#             */
/*   Updated: 2021/09/22 08:05:58 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_pos(t_general *g)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (g->m.tab[i])
	{
		j = 0;
		while (g->m.tab[i][j])
		{
			if (check_is_pos(g, g->m.tab[i][j]))
			{
				k++;
				g->game.pos_x = j;
				g->game.pos_y = i;
			}
			if (k > 1)
				free_tab_m(4, g);
			j++;
		}
		i++;
	}
	if (k == 0)
		free_tab_m(5, g);
}

void	free_tab_m(int c, t_general *g)
{
	int	i;

	i = 0;
	while (g->m.tab[i])
	{
		free(g->m.tab[i]);
		i++;
	}
	free(g->m.tab);
	err2(c);
	exit(1);
}

int	check_wall_line(char *line, t_general *g)
{
	int		i;
	char	first;
	char	last;

	first = 'a';
	last = 'a';
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			;
		else
		{
			if (first == 'a')
				first = line[i];
			last = line[i];
			g->m.len = i;
		}
		i++;
	}
	if (first != '1' || last != '1')
		return (0);
	return (1);
}

int	check_only_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	get_len(char *line, int c, t_general *g)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	while (line[len - 1] == ' ')
		len--;
	if (c == 1)
		g->m.len_b = len;
	if (c == 2)
		g->m.len_n = len;
}

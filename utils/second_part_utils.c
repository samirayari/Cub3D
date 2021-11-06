/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:23:29 by sayari            #+#    #+#             */
/*   Updated: 2021/10/21 13:53:21 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_valid_char(int c)
{
	if (c == '1' || c == '0')
		return (1);
	if (c == 'N' || c == 'S')
		return (1);
	if (c == 'E' || c == 'W')
		return (1);
	if (ft_isspace(c))
		return (1);
	return (0);
}

void	free_tab(t_general *g)
{
	int	i;

	i = 0;
	while (g->m.tab[i])
	{
		free(g->m.tab[i]);
		i++;
	}
	free(g->m.tab);
	exit(1);
}

int	map_empty_line(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	if (line[i] == 0)
		return (1);
	while (ft_isspace(line[i]))
		i++;
	if (i == len)
		return (1);
	return (0);
}

void	map_check_first(t_general *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->m.tab[i])
	{
		j = 0;
		if (map_empty_line(g->m.tab[i]))
		{
			ft_putstr("Error\nEmpty line in map!\n");
			free_tab(g);
		}
		while (g->m.tab[i][j])
		{
			if (!(is_valid_char(g->m.tab[i][j])))
			{
				ft_putstr("Error\nInvalid character in map\n");
				free_tab(g);
			}
			j++;
		}
		i++;
	}
}

int	check_is_pos(t_general *g, char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		g->m.d = c;
		return (1);
	}
	return (0);
}

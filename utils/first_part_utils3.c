/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:00:15 by sayari            #+#    #+#             */
/*   Updated: 2021/11/01 15:51:36 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_only_comma_and_int(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ',' && (!(ft_isdigit(str[i])))
			&& (ft_isspace(str[i]) != 1))
		{
			if (c == 1)
				ft_putstr("Error\nInvalid arg in floor color\n");
			if (c == 2)
				ft_putstr("Error\nInvalid arg in cell color\n");
			free(str);
			exit(1);
		}
		i++;
	}
}

void	check_valid_color(char *color, t_general *g)
{
	char	**color_tab;
	int		i;

	i = 0;
	if ((g->m.line[0] == 'F') && (ft_isspace(g->m.line[1])))
	{
		check_only_comma_and_int(color, 1);
		color_tab = ft_split(color, ',');
		check_color_floor(color_tab, g);
		free_color(color_tab, color);
	}
	if ((g->m.line[0] == 'C') && (ft_isspace(g->m.line[1])))
	{
		check_only_comma_and_int(color, 2);
		color_tab = ft_split(color, ',');
		check_color_cell(color_tab, g);
		free_color(color_tab, color);
	}
}

void	check_line_color(t_general *g)
{
	int		i;
	int		j;
	char	*color;
	int		len;

	i = 1;
	g->m.type++;
	len = ft_strlen(g->m.line);
	while (ft_isspace(g->m.line[i]))
		i++;
	j = i;
	while ((ft_isspace(g->m.line[--len])))
		;
	color = ft_substr(g->m.line, i, len - i + 1);
	check_valid_color(color, g);
}

void	check_one_color(t_general *g)
{
	if (g->m.f == 2)
	{
		ft_putstr("Error\nseveral times the same type color : F !\n");
		exit(1);
	}
	if (g->m.c == 2)
	{
		ft_putstr("Error\nseveral times the same type color : C !\n");
		exit(1);
	}
}

int	check_color(t_general *g)
{
	if (g->m.line[0] == 'F' && (ft_isspace(g->m.line[1])))
	{
		g->m.f++;
		check_one_color(g);
		return (1);
	}
	if (g->m.line[0] == 'C' && (ft_isspace(g->m.line[1])))
	{
		g->m.c++;
		check_one_color(g);
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:14:41 by sayari            #+#    #+#             */
/*   Updated: 2021/09/17 14:41:12 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_first_part(t_general *g)
{
	g->m.len = ft_strlen(g->m.line);
	if (check_identifier(g))
		check_line_identifier(g);
	else if (check_color(g))
		check_line_color(g);
	else if (its_empty_line(g))
		;
	else
		err(5);
}

int	parsing_first(t_general *g, int ret)
{
	while (ret > 0)
	{
		ret = get_next_line(g->m.fd, &g->m.line);
		if (ret == -1)
			err(2);
		if (ret == 0)
			break ;
		if (g->m.type == 6)
		{
			if (check_after_type(g) == 1 && g->m.first_line == 0)
				g->m.first_line = g->m.i;
			if (check_after_type(g) == 1 && g->m.first_line != 0)
				g->m.last_line = g->m.i;
		}
		else
			check_first_part(g);
		g->m.i++;
		free(g->m.line);
	}
	close(g->m.fd);
	if (g->m.type != 6)
		err(6);
	else if (g->m.first_line == 0)
		err(7);
	return (0);
}

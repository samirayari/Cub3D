/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part_utils4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:25:34 by sayari            #+#    #+#             */
/*   Updated: 2021/09/22 08:06:34 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	reach_first_line(t_general *g)
{
	int	i;

	i = 0;
	while (g->m.line[i])
	{
		if (g->m.line[i] != ' ' || g->m.line[i] != '1')
		{
			printf("error\n");
			exit(1);
		}
		i++;
	}
}

int	check_after_type(t_general *g)
{
	if (check_identifier(g))
		check_line_identifier(g);
	else if (check_color(g))
		check_line_color(g);
	else if (its_empty_line(g))
		;
	else
		return (1);
	return (0);
}

int	its_empty_line(t_general *g)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(g->m.line);
	if (g->m.line[i] == 0)
		return (1);
	while (ft_isspace(g->m.line[i]))
		i++;
	if (i == len)
		return (1);
	return (0);
}

void	close_and_free(t_general *g, char *texture, int c)
{
	g->m.fd_test = open(texture, O_RDONLY);
	if (c == 1)
		if (g->m.fd_test == -1)
			err_texture(1, g);
	if (c == 2)
		if (g->m.fd_test == -1)
			err_texture(2, g);
	if (c == 3)
		if (g->m.fd_test == -1)
			err_texture(3, g);
	if (c == 4)
		if (g->m.fd_test == -1)
			err_texture(4, g);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_the_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:28:08 by sayari            #+#    #+#             */
/*   Updated: 2021/10/21 13:52:35 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	take_the_map(t_general *g, char *av[])
{
	int	i;

	i = 0;
	g->m.tab = NULL;
	g->m.size = g->m.last_line - (g->m.first_line - 1);
	g->m.tab = malloc(sizeof(char *) * (g->m.size + 1));
	fill_tab(g, av);
}

void	fill_tab(t_general *g, char *av[])
{
	int		i;
	int		j;
	int		ret;
	char	*line;

	i = 0;
	j = 0;
	ret = 1;
	line = NULL;
	g->m.fd = open(av[1], O_RDONLY);
	while (ret >= 0)
	{
		ret = get_next_line(g->m.fd, &line);
		if (ret == 0)
			break ;
		if (i >= g->m.first_line && i <= g->m.last_line)
		{
			g->m.tab[j] = ft_strdup(line);
			j++;
		}
		free(line);
		i++;
	}
	free(line);
	g->m.tab[j] = NULL;
}

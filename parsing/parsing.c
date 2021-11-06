/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 08:19:16 by sayari            #+#    #+#             */
/*   Updated: 2021/09/22 10:47:55 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parsing(t_general *g, char *av[])
{
	parsing_first(g, 1);
	take_the_map(g, av);
	close(g->m.fd);
	map_check_first(g);
	check_pos(g);
	check_map(g);
}

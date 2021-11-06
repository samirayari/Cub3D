/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:57:07 by sayari            #+#    #+#             */
/*   Updated: 2021/09/22 10:34:40 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_general(t_general *g, char *av[])
{
	g->m.fd = open(av[1], O_RDONLY);
	g->m.line = NULL;
	g->m.i = 0;
	g->m.type = 0;
	g->m.ea = 0;
	g->m.so = 0;
	g->m.no = 0;
	g->m.we = 0;
	g->m.c = 0;
	g->m.f = 0;
	g->m.first_line = 0;
	g->m.last_line = 0;
	g->m.len_n = 0;
	g->m.len_b = 0;
	g->m.len_nn = 0;
	g->m.len_bb = 0;
	g->m.size = 0;
	g->i = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 08:50:01 by sayari            #+#    #+#             */
/*   Updated: 2021/11/02 17:01:36 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	load_texture(t_general *g)
{
	g->mlx.wall_n = mlx_xpm_file_to_image(g->mlx.mlx, g->mlx.c_n,
			&g->mlx.i_width, &g->mlx.i_height);
	g->mlx.wall_s = mlx_xpm_file_to_image(g->mlx.mlx, g->mlx.c_s,
			&g->mlx.i_width, &g->mlx.i_height);
	g->mlx.wall_e = mlx_xpm_file_to_image(g->mlx.mlx, g->mlx.c_e,
			&g->mlx.i_width, &g->mlx.i_height);
	g->mlx.wall_w = mlx_xpm_file_to_image(g->mlx.mlx, g->mlx.c_w,
			&g->mlx.i_width, &g->mlx.i_height);
	g->mlx.a_n = (int *)mlx_get_data_addr(g->mlx.wall_n,
			&g->img.bits_per_pixel_n, &g->img.line_length_n, &g->img.endian_n);
	g->mlx.a_s = (int *)mlx_get_data_addr(g->mlx.wall_s,
			&g->img.bits_per_pixel_s, &g->img.line_length_s, &g->img.endian_s);
	g->mlx.a_e = (int *)mlx_get_data_addr(g->mlx.wall_e,
			&g->img.bits_per_pixel_e, &g->img.line_length_e, &g->img.endian_e);
	g->mlx.a_w = (int *)mlx_get_data_addr(g->mlx.wall_w,
			&g->img.bits_per_pixel_w, &g->img.line_length_w, &g->img.endian_w);
}

int	main(int ac, char *av[])
{
	t_general	g;

	if (check_arg(av, ac) != 1)
		err(1);
	init_general(&g, av);
	parsing(&g, av);
	g.mlx.mlx = mlx_init();
	g.mlx.win = mlx_new_window(g.mlx.mlx, 1920, 1080, "cub3D");
	g.mlx.img = mlx_new_image(g.mlx.mlx, 1920, 1080);
	g.mlx.addr = mlx_get_data_addr(g.mlx.img,
			&g.mlx.bits_per_pixel, &g.mlx.line_length, &g.mlx.endian);
	load_texture(&g);
	start_angle(&g);
	in_game(&g);
	redisplay(&g);
	mlx_key_hook(g.mlx.win, ft_key, &g);
	mlx_hook(g.mlx.win, 17, 0, close_win, &g);
	mlx_put_image_to_window(g.mlx.mlx, g.mlx.win, g.mlx.img, 0, 0);
	mlx_hook(g.mlx.win, 2, 1L << 0, ft_key, &g);
	mlx_loop(g.mlx.mlx);
}

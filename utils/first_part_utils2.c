/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:49:37 by sayari            #+#    #+#             */
/*   Updated: 2021/11/01 16:07:30 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_ext_texture(char *texture)
{
	int	len;

	len = ft_strlen(texture);
	while (len > 0)
	{
		if (texture[len] == '.')
		{
			if ((texture[len + 1] != 'x') || (texture[len + 2] != 'p')
				|| ((texture[len + 3] != 'm') || (texture[len + 4])))
			{
				ft_putstr("Error\nPath extension not valid !\n");
				exit(1);
			}
		}
		len--;
	}
}

void	err_texture(int c, t_general *g)
{
	if (c == 1)
	{
		close(g->m.fd_test);
		ft_putstr("Error\nTexture path (NO) invalid !\n");
		exit(1);
	}
	if (c == 2)
	{
		close(g->m.fd_test);
		ft_putstr("Error\nTexture path (SO) invalid !\n");
		exit(1);
	}
	if (c == 3)
	{
		close(g->m.fd_test);
		ft_putstr("Error\nTexture path (EA) invalid !\n");
		exit(1);
	}
	if (c == 4)
	{
		close(g->m.fd_test);
		ft_putstr("Error\nTexture path (WE) invalid !\n");
		exit(1);
	}
}

void	check_value(int r, int g, int b)
{
	if (r < 0 || r > 255)
		ft_putstr("Error\nFloor Value invalid !");
	if (g < 0 || g > 255)
		ft_putstr("Error\nFloor Value invalid !");
	if (b < 0 || b > 255)
		ft_putstr("Error\nFloor Value invalid !");
}

void	check_color_floor(char **str, t_general *g)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 3)
	{
		ft_putstr("Error\nThere are not the right number of arguments\n");
		exit(1);
	}
	i = 0;
	while (i < 3)
	{
		if (i == 0)
			g->f_r = ft_atoi(str[i]);
		if (i == 1)
			g->f_g = ft_atoi(str[i]);
		if (i == 2)
			g->f_b = ft_atoi(str[i]);
		i++;
	}
	check_value(g->f_r, g->f_g, g->f_b);
}

void	check_color_cell(char **str, t_general *g)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 3)
	{
		ft_putstr("Error\nThere are not the right number of arguments\n");
		exit(1);
	}
	i = 0;
	while (i < 3)
	{
		if (i == 0)
			g->c_r = ft_atoi(str[i]);
		if (i == 1)
			g->c_g = ft_atoi(str[i]);
		if (i == 2)
			g->c_b = ft_atoi(str[i]);
		i++;
	}
	check_value(g->c_r, g->c_g, g->c_b);
}

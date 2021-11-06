/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 09:10:19 by sayari            #+#    #+#             */
/*   Updated: 2021/09/22 08:04:49 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_putstr(char *s)
{
	if (s)
		while (*s)
			write(1, s++, 1);
}

void	err(int c)
{
	if (c == 1)
		ft_putstr("Error\nInvalid argument\n");
	if (c == 2)
		ft_putstr("Error\nFile empty\n");
	if (c == 3)
		ft_putstr("Error\nConfiguration fail\n");
	if (c == 4)
		ft_putstr("Error\nPath its Directory\n");
	if (c == 5)
		ft_putstr("Error\nParameters line invalid\n");
	if (c == 6)
		ft_putstr("Error\nParameters missing :(\n");
	if (c == 7)
		ft_putstr("Error\nMissing map\n");
	exit(1);
}

void	free_color(char **color_tab, char *color)
{
	int	i;

	i = 0;
	free(color);
	while (color_tab[i])
		free(color_tab[i++]);
	free(color_tab);
}

void	err_and_free(int c, char **str)
{
	int	i;

	i = 0;
	if (c == 1)
	{
		while (str[i])
			free(str[i++]);
	}
}

void	err2(int c)
{
	if (c == 1)
		ft_putstr("Error\nInvalid caracter in line\n");
	if (c == 2)
		ft_putstr("Error\nMap open !\n");
	if (c == 3)
		ft_putstr("Error\nHole in the map!\n");
	if (c == 4)
		ft_putstr("Error\nTo much start_position !\n");
	if (c == 5)
		ft_putstr("Error\nNo start position !\n");
}

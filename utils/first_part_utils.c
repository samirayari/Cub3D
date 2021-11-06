/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:56:35 by sayari            #+#    #+#             */
/*   Updated: 2021/11/02 09:41:09 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_one_identifier(t_general *g)
{
	if (g->m.no == 2)
	{
		ft_putstr("Error\nseveral times the same type identifier : NO !\n");
		exit(1);
	}
	if (g->m.so == 2)
	{
		ft_putstr("Error\nseveral times the same type identifier : SO !\n");
		exit(1);
	}
	if (g->m.ea == 2)
	{
		ft_putstr("Error\nseveral times the same type identifier : EA !\n");
		exit(1);
	}
	if (g->m.we == 2)
	{
		ft_putstr("Error\nseveral times the same type identifier : WE !\n");
		exit(1);
	}
}

int	check_identifier(t_general *g)
{
	if (!(ft_strncmp(g->m.line, "NO", 2)) && (ft_isspace(g->m.line[2])))
	{
		g->m.no++;
		check_one_identifier(g);
		return (1);
	}
	if (!(ft_strncmp(g->m.line, "SO", 2)) && (ft_isspace(g->m.line[2])))
	{
		g->m.so++;
		check_one_identifier(g);
		return (1);
	}
	if (!(ft_strncmp(g->m.line, "EA", 2)) && (ft_isspace(g->m.line[2])))
	{
		g->m.ea++;
		check_one_identifier(g);
		return (1);
	}
	if (!(ft_strncmp(g->m.line, "WE", 2)) && (ft_isspace(g->m.line[2])))
	{
		g->m.we++;
		check_one_identifier(g);
		return (1);
	}
	return (0);
}

void	check_valid_texture(char *texture, t_general *g)
{
	if (!(ft_strncmp(g->m.line, "NO", 2)) && (ft_isspace(g->m.line[2])))
	{
		check_ext_texture(texture);
		g->m.fd_test = open(texture, O_DIRECTORY);
		if (g->m.fd_test > 0)
			err(4);
		close(g->m.fd_test);
		close_and_free(g, texture, 1);
		g->mlx.c_n = ft_strdup(texture);
		free(texture);
	}
	if (!(ft_strncmp(g->m.line, "SO", 2)) && (ft_isspace(g->m.line[2])))
	{
		check_ext_texture(texture);
		g->m.fd_test = open(texture, O_DIRECTORY);
		if (g->m.fd_test > 0)
			err(4);
		close_and_free(g, texture, 2);
		g->mlx.c_s = ft_strdup(texture);
		free(texture);
	}
	check_valid_texture2(texture, g);
}

void	check_valid_texture2(char *texture, t_general *g)
{
	if (!(ft_strncmp(g->m.line, "EA", 2)) && (ft_isspace(g->m.line[2])))
	{
		check_ext_texture(texture);
		g->m.fd_test = open(texture, O_DIRECTORY);
		if (g->m.fd_test > 0)
			err(4);
		close(g->m.fd_test);
		close_and_free(g, texture, 3);
		g->mlx.c_e = ft_strdup(texture);
		free(texture);
	}
	if (!(ft_strncmp(g->m.line, "WE", 2)) && (ft_isspace(g->m.line[2])))
	{
		check_ext_texture(texture);
		g->m.fd_test = open(texture, O_DIRECTORY);
		if (g->m.fd_test > 0)
			err(4);
		close(g->m.fd_test);
		close_and_free(g, texture, 4);
		g->mlx.c_w = ft_strdup(texture);
		free(texture);
	}
}

void	check_line_identifier(t_general *g)
{
	int		i;
	int		j;
	char	*texture;

	i = 2;
	g->m.type++;
	while (ft_isspace(g->m.line[i]))
		i++;
	j = i;
	while (!(ft_isspace(g->m.line[j])))
		j++;
	texture = ft_substr(g->m.line, i, j - i);
	while (ft_isspace(g->m.line[j]))
		j++;
	if (!(ft_isspace(g->m.line[j])))
	{
		if (j == g->m.len)
			check_valid_texture(texture, g);
		else
		{
			free(texture);
			ft_putstr("Error\nConfiguration file : texture !\n");
			exit(1);
		}
	}
}

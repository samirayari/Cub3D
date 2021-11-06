/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 09:31:44 by sayari            #+#    #+#             */
/*   Updated: 2021/09/06 10:40:12 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_arg(char *av[], int ac)
{
	int	d_fd;
	int	fd;

	if (ac != 2)
		return (0);
	d_fd = open(av[1], O_DIRECTORY);
	if (d_fd != -1)
		return (0);
	close(d_fd);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	if (ft_strstr(av[1], ".cub") == 0)
		return (0);
	return (1);
}

int	ft_strstr(char *s1, char *s2)
{
	int	i;
	int	j;

	if (!s1)
		return (0);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if (s1[i + j + 1] == s2[j + 1] && s2[j + 1] == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

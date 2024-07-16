/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:05:36 by jesumore          #+#    #+#             */
/*   Updated: 2024/07/16 22:11:39 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_necessary_stuff(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(map[y][x] == '1' || map[y][x] == '0' || map[y][x] == 'E'
				|| map[y][x] == 'P' || map[y][x] == 'C'))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_walls(t_game *game, char **map)
{
	size_t	line;
	size_t	i;
	size_t	j;

	line = 0;
	while (map[line])
		line++;
	i = 0;
	while (i < ft_strlen(map[0]))
	{
		if (map[0][i] != '1' || map[line - 1][i] != '1')
			return (1);
		i++;
	}
	j = 0;
	while (j < line)
	{
		if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
			return (1);
		j++;
	}
	game->height = line * 32;
	game->width = ft_strlen(map[0]) * 32;
	return (0);
}

int	check_e_p_c(t_game *game, char **map)
{
	int	i;
	int	j;
	int	num_e_p;
	int	num_c;

	i = 0;
	num_e_p = 0;
	num_c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'P')
				num_e_p++;
			if (map[i][j] == 'C')
				num_c++;
			j++;
		}
		i++;
	}
	if (num_e_p != 2 || num_c < 1)
		return (1);
	game->collect = num_c;
	return (0);
}

int	valid_route(t_game *game, char *fd)
{
	int	*pos;

	game->map_copy = read_map(fd);
	pos = start_pos(game->map_copy);
	game->pos_y = pos[0];
	game->pos_x = pos[1];
	flood_fill(game, pos[0], pos[1]);
	if (check_flood(game->map_copy) == 1)
	{
		free(pos);
		free_map(game->map_copy);
		return (ft_printf("Error:\n%s", ROUTE_ERROR), 1);
	}
	free(pos);
	free_map(game->map_copy);
	return (0);
}

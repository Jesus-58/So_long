/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:18:47 by jesumore          #+#    #+#             */
/*   Updated: 2024/06/18 18:56:41 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*start_pos(char **map)
{
	int	*pos;
	int	x;
	int	y;

	pos = (int *)ft_calloc(2, sizeof(int));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				pos[0] = y;
				pos[1] = x;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

void	flood_fill(t_game *game, int y, int x)
{
	if (!(x < 1 || x >= game->width || y < 1 || y >= game->height
			|| game->map_copy[y][x] == '1' || game->map_copy[y][x] == 'V'))
	{
		game->map_copy[y][x] = 'V';
		flood_fill(game, y + 1, x);
		flood_fill(game, y - 1, x);
		flood_fill(game, y, x + 1);
		flood_fill(game, y, x - 1);
	}
}

int	check_flood(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'V'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

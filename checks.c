/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:00:07 by jesumore          #+#    #+#             */
/*   Updated: 2024/07/16 22:11:47 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ext_check(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[len - 4] != '.' || map_name[len - 3] != 'b'
		|| map_name[len - 2] != 'e' || map_name[len - 1] != 'r')
		return (ft_printf(EXT_ERROR), 1);
	return (0);
}

int	check_map_exist(const char *map_name)
{
	int	file;

	file = open(map_name, O_RDONLY);
	if (file == -1)
	{
		return (1);
		close(file);
	}
	return (0);
}

int	check_map_empty(char **map)
{
	if (map == NULL || map[0] == NULL)
		return (1);
	return (0);
}

int	check_map_rectang(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (1);
		i++;
	}
	return (0);
}

int	check_map(t_game *game, char **map)
{
	if (1 == check_map_empty(map))
		return (ft_printf("Error:\n%s", EMPTY_ERROR), 1);
	if (1 == check_map_rectang(map))
		return (ft_printf("Error:\n%s", RECTANG_ERROR), 1);
	if (1 == check_necessary_stuff(map))
		return (ft_printf("Error:\n%s", COMPONENT_ERROR), 1);
	if (1 == check_walls(game, map))
		return (ft_printf("Error:\n%s", WALL_ERROR), 1);
	if (1 == check_e_p_c(game, map))
		return (ft_printf("Error:\n%s", E_P_C_ERROR), 1);
	return (0);
}

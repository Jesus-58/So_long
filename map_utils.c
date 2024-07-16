/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:33:09 by jesumore          #+#    #+#             */
/*   Updated: 2024/06/15 21:01:01 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *script_map)
{
	int		fd;
	char	*temp_map;
	char	**map;
	int		n;

	n = 0;
	temp_map = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if (!temp_map)
		return (0);
	fd = open(script_map, O_RDONLY);
	if (fd < 0)
	{
		free(temp_map);
		return (0);
	}
	n = read(fd, temp_map, BUFF_SIZE);
	if (n == -1 || n == 0)
	{
		free(temp_map);
		return (0);
	}
	map = ft_split(temp_map, '\n');
	free(temp_map);
	close(fd);
	return (map);
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

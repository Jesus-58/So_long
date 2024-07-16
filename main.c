/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:02:24 by jesumore          #+#    #+#             */
/*   Updated: 2024/07/16 22:16:31 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	char	*map_name;

	if (argc != 2)
		return (ft_printf("Error:\n%s", ARG_ERROR), 1);
	map_name = argv[1];
	ext_check(map_name);
	if (check_map_exist(map_name) == 1)
		return (ft_printf("Error:\n%s", EXIST_ERROR), 1);
	game = (t_game *)malloc(sizeof(t_game));
	game->map = read_map(argv[1]);
	if (!game->map)
		return (1);
	if (check_map(game, game->map) == 1)
		return (free_map(game->map), 1);
	if (valid_route(game, argv[1]) == 1)
		return (free_map(game->map), 1);
	if (init_game(game) == 1)
		return (1);
	return (0);
}

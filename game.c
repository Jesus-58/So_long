/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:01:27 by jesumore          #+#    #+#             */
/*   Updated: 2024/07/16 21:38:11 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game)
{
	game->moves = 0;
	game->collected = 0;
	ft_get_textures(game);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	game->mlx = mlx_init(game->width, game->height, "So_Long", true);
	if (!(game->mlx))
		return (1);
	ft_get_images(game);
	ft_print_map(game, game->img);
	game->pos_x = game->img->pj->instances->x;
	game->pos_y = game->img->pj->instances->y;
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->map);
	free(game->textu);
	free(game->img);
	return (0);
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if ((keydata.key == 87 || keydata.key == 265)
		&& (keydata.action == 1 || keydata.action == 2))
		ft_move_up(game);
	if ((keydata.key == 83 || keydata.key == 264)
		&& (keydata.action == 1 || keydata.action == 2))
		ft_move_down(game);
	if ((keydata.key == 65 || keydata.key == 263)
		&& (keydata.action == 1 || keydata.action == 2))
		ft_move_left(game);
	if ((keydata.key == 68 || keydata.key == 262)
		&& (keydata.action == 1 || keydata.action == 2))
		ft_move_right(game);
	if (keydata.key == 256 && keydata.action == 0)
		mlx_close_window(game->mlx);
	collectables(game);
}

void	collectables(t_game *game)
{
	if (game->map[game->pos_y / 32][game->pos_x / 32] == 'C')
	{
		ft_remove_collect(game);
		game->map[game->pos_y / 32][game->pos_x / 32] = '0';
		game->collected++;
		if (game->collected == game->collect)
		{
			game->img->exit_1->instances->enabled = false;
			game->img->exit_2->instances->enabled = true;
		}
	}
	if (game->map[game->pos_y / 32][game->pos_x / 32] == 'E')
	{
		if (game->collected == game->collect)
			mlx_close_window(game->mlx);
	}
}

void	ft_remove_collect(t_game *game)
{
	int	i;
	int	c_count;

	c_count = game->collect;
	i = 0;
	while (i < c_count)
	{
		if ((game->img->collec->instances[i].y == game->pos_y)
			&& (game->img->collec->instances[i].x == game->pos_x)
			&& game->img->collec->instances[i].enabled == true)
		{
			c_count--;
			game->img->collec->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

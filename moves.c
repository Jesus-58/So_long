/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:08:32 by jesumore          #+#    #+#             */
/*   Updated: 2024/07/16 20:49:35 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_game *game)
{
	if (game->map[game->pos_y / 32 - 1][game->pos_x / 32] != '1')
	{
		game->img->pj->instances->y -= 32;
		game->pos_y = game->img->pj->instances->y;
		game->moves++;
		ft_printf("Moves: %i\n", game->moves);
	}
}

void	ft_move_down(t_game *game)
{
	if (game->map[game->pos_y / 32 + 1][game->pos_x / 32] != '1')
	{
		game->img->pj->instances->y += 32;
		game->pos_y = game->img->pj->instances->y;
		game->moves++;
		ft_printf("Moves: %i\n", game->moves);
	}
}

void	ft_move_left(t_game *game)
{
	if (game->map[game->pos_y / 32][game->pos_x / 32 - 1] != '1')
	{
		game->img->pj->instances->x -= 32;
		game->pos_x = game->img->pj->instances->x;
		game->moves++;
		ft_printf("Moves: %i\n", game->moves);
	}
}

void	ft_move_right(t_game *game)
{
	if (game->map[game->pos_y / 32][game->pos_x / 32 + 1] != '1')
	{
		game->img->pj->instances->x += 32;
		game->pos_x = game->img->pj->instances->x;
		game->moves++;
		ft_printf("Moves: %i\n", game->moves);
	}
}

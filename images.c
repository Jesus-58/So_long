/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:37:12 by jesumore          #+#    #+#             */
/*   Updated: 2024/07/16 22:10:59 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_textures(mlx_texture_t **txs, char *path)
{
	*txs = mlx_load_png(path);
	if (*txs == NULL)
		exit(1);
}

void	ft_get_textures(t_game *game)
{
	game->textu = ft_calloc(1, sizeof(t_textu));
	check_textures(&game->textu->floor, "img/floor.png");
	check_textures(&game->textu->wall, "img/wall.png");
	check_textures(&game->textu->exit_1, "img/exit_1.png");
	check_textures(&game->textu->exit_2, "img/exit_2.png");
	check_textures(&game->textu->collec, "img/Red_Rupee.png");
	check_textures(&game->textu->pj, "img/link_front.png");
}

void	ft_get_images(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_img));
	game->img->floor = mlx_texture_to_image(game->mlx, game->textu->floor);
	game->img->wall = mlx_texture_to_image(game->mlx, game->textu->wall);
	game->img->exit_1 = mlx_texture_to_image(game->mlx, game->textu->exit_1);
	game->img->exit_2 = mlx_texture_to_image(game->mlx, game->textu->exit_2);
	game->img->collec = mlx_texture_to_image(game->mlx, game->textu->collec);
	game->img->pj = mlx_texture_to_image(game->mlx, game->textu->pj);
	mlx_delete_texture(game->textu->floor);
	mlx_delete_texture(game->textu->wall);
	mlx_delete_texture(game->textu->exit_1);
	mlx_delete_texture(game->textu->exit_2);
	mlx_delete_texture(game->textu->collec);
	mlx_delete_texture(game->textu->pj);
}

void	ft_print_map(t_game *game, t_img *img)
{
	int	x;
	int	y;

	ft_print_floor(game, game->img);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, img->collec, x * 32, y * 32);
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, img->pj, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	ft_print_floor(t_game *game, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, img->floor, x * 32, y * 32);
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, img->wall, x * 32, y * 32);
			if (game->map[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx, img->exit_2, x * 32, y * 32);
				mlx_image_to_window(game->mlx, img->exit_1, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}

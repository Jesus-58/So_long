/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesumore <jesumore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:41:39 by jesumore          #+#    #+#             */
/*   Updated: 2024/07/16 22:09:48 by jesumore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "Libft/libft.h"
# include "Printf/ft_printf.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define BUFF_SIZE 10000
# define ARG_ERROR "only two arguments available\n"
# define EXIST_ERROR "the map does not exist\n"
# define EXT_ERROR "map extension incorrect\n"
# define EMPTY_ERROR "the map is empty\n"
# define RECTANG_ERROR "map is not rectangular\n"
# define COMPONENT_ERROR "some components are incorrect\n"
# define WALL_ERROR "walls error\n"
# define E_P_C_ERROR "error with the collectables or exit\n"
# define ROUTE_ERROR "not a path available to complete level\n"

typedef struct s_textu
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*pj;
	mlx_texture_t	*enemy;
	mlx_texture_t	*collec;
	mlx_texture_t	*exit_1;
	mlx_texture_t	*exit_2;
}	t_textu;

typedef struct s_img
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*pj;
	mlx_image_t	*enemy;
	mlx_image_t	*collec;
	mlx_image_t	*exit_1;
	mlx_image_t	*exit_2;
}	t_img;

typedef struct s_game
{
	mlx_t	*mlx;
	t_textu	*textu;
	t_img	*img;
	char	**map;
	char	**map_copy;
	int		collect;
	int		collected;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
	int		moves;

}	t_game;

//	check errors

int		ext_check(char *map_name);
int		check_map_exist(const char *map_name);
int		check_map(t_game *game, char **map);
int		check_map_empty(char **map);
int		check_map_rectang(char **map);
int		check_necessary_stuff(char **map);
int		check_walls(t_game *game, char **map);
int		check_e_p_c(t_game *game, char **map);
int		valid_route(t_game *game, char *fd);
int		*start_pos(char **map);
int		check_flood(char **map);
void	flood_fill(t_game *game, int y, int x);

//	map utils

char	**read_map(char *script_map);
void	free_map(char **map);

//	game utils

int		init_game(t_game *game);
void	ft_get_textures(t_game *game);
void	ft_get_images(t_game *game);
void	ft_print_map(t_game *game, t_img *img);
void	ft_print_floor(t_game *game, t_img *img);
void	my_key_hook(mlx_key_data_t keydata, void *param);
void	collectables(t_game *game);
void	ft_remove_collect(t_game *game);

//	Movements

void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);

#endif
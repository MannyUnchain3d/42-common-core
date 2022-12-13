/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:55:52 by Manny             #+#    #+#             */
/*   Updated: 2022/12/05 01:44:17 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	put_enemy_img_bonus(int i, int j, t_map *map, t_mlx mlx)
{
	if (map->map_data[i][j] == 'N')
	{
		if ((int)time(NULL) % 2 == 0)

			mlx_put_image_to_window(mlx.ptr, mlx.win,
				map->img.enemy.enemy_right, CELL_SIZE * j, CELL_SIZE * i);
		else
			mlx_put_image_to_window(mlx.ptr, mlx.win,
				map->img.enemy.enemy_left, CELL_SIZE * j, CELL_SIZE * i);
	}
}

static void	put_img_bonus(int i, int j, t_map *map, t_mlx mlx)
{
	if (map->map_data[i][j] == '0')
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.floor,
			CELL_SIZE * j, CELL_SIZE * i);
	else if (map->map_data[i][j] == '1')
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.wall,
			CELL_SIZE * j, CELL_SIZE * i);
	else if (map->map_data[i][j] == 'P')
	{
		map->player_position.x = j;
		map->player_position.y = i;
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.player,
			CELL_SIZE * j, CELL_SIZE * i);
	}
	else if (map->map_data[i][j] == 'E')
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.exit,
			CELL_SIZE * j, CELL_SIZE * i);
	else if (map->map_data[i][j] == 'C')
	{
		(map->items_to_collect)++;
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.collectible,
			CELL_SIZE * j, CELL_SIZE * i);
	}
}

static void	count_items_to_collect(int i, int j, t_map *map)
{
	if (map->map_data[i][j] == 'C')
		(map->items_to_collect)++;
}

void	img_to_win_bonus(t_game *game)
{
	int		i;
	int		j;
	char	*counter_str;

	game->map.items_to_collect = 0;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			count_items_to_collect(i, j, &(game->map));
			put_img_bonus(i, j, &(game->map), game->mlx);
			put_enemy_img_bonus(i, j, &(game->map), game->mlx);
			j++;
		}
		i++;
	}
	counter_str = ft_itoa(game->steps);
	mlx_string_put(game->mlx.ptr, game->mlx.win, 70, 70, 0xFFFFFF,
		"Move count:");
	mlx_string_put(game->mlx.ptr, game->mlx.win, 140, 70, 0xFFFFFF,
		counter_str);
	free(counter_str);
}

void	img_init_bonus(t_mlx *mlx, t_img *img)
{
	int	pos[2];

	img->floor = mlx_xpm_file_to_image(mlx->ptr, FLOOR_PATH,
			&pos[0], &pos[1]);
	img->wall = mlx_xpm_file_to_image(mlx->ptr, WALL_PATH,
			&pos[0], &pos[1]);
	img->player = mlx_xpm_file_to_image(mlx->ptr, PLAYER_PATH,
			&pos[0], &pos[1]);
	img->collectible = mlx_xpm_file_to_image(mlx->ptr, COLLECTIBLE_PATH,
			&pos[0], &pos[1]);
	img->exit = mlx_xpm_file_to_image(mlx->ptr, EXIT_PATH,
			&pos[0], &pos[1]);
	img->enemy.enemy_right = mlx_xpm_file_to_image(mlx->ptr, ENEMY_RIGHT_PATH,
			&pos[0], &pos[1]);
	img->enemy.enemy_left = mlx_xpm_file_to_image(mlx->ptr, ENEMY_LEFT_PATH,
			&pos[0], &pos[1]);
}

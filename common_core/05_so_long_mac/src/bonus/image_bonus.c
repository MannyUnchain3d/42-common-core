/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:55:52 by Manny             #+#    #+#             */
/*   Updated: 2022/12/20 16:40:57 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	put_enemy_img_bonus(int row, int col, t_map *map, t_mlx mlx)
{
	if (map->map_data[row][col] == 'N')
	{
		if ((int)time(NULL) % 2 == 0)
			mlx_put_image_to_window(mlx.ptr, mlx.win,
				map->img.enemy.enemy_right, CELL_SIZE * col, CELL_SIZE * row);
		else
			mlx_put_image_to_window(mlx.ptr, mlx.win,
				map->img.enemy.enemy_left, CELL_SIZE * col, CELL_SIZE * row);
	}
}

static void	put_img_bonus(int row, int col, t_map *map, t_mlx mlx)
{
	if (map->map_data[row][col] == '0')
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.floor,
			CELL_SIZE * col, CELL_SIZE * row);
	else if (map->map_data[row][col] == '1')
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.wall,
			CELL_SIZE * col, CELL_SIZE * row);
	else if (map->map_data[row][col] == 'P')
	{
		map->player_pos.col = col;
		map->player_pos.row = row;
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.player,
			CELL_SIZE * col, CELL_SIZE * row);
	}
	else if (map->map_data[row][col] == 'E')
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.exit,
			CELL_SIZE * col, CELL_SIZE * row);
	else if (map->map_data[row][col] == 'C')
	{
		(map->items_to_collect)++;
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.collectible,
			CELL_SIZE * col, CELL_SIZE * row);
	}
}

static void	count_items_to_collect(int row, int col, t_map *map)
{
	if (map->map_data[row][col] == 'C')
		(map->items_to_collect)++;
}

void	img_to_win_bonus(t_game *game)
{
	int		row;
	int		col;
	char	*counter_str;

	game->map.items_to_collect = 0;
	row = 0;
	while (row < game->map.height)
	{
		col = 0;
		while (col < game->map.width)
		{
			count_items_to_collect(row, col, &(game->map));
			put_img_bonus(row, col, &(game->map), game->mlx);
			put_enemy_img_bonus(row, col, &(game->map), game->mlx);
			col++;
		}
		row++;
	}
	counter_str = ft_itoa(game->steps);
	mlx_string_put(game->mlx.ptr, game->mlx.win, 70, 70, 0xFFFFFF,
		"Move count:");
	mlx_string_put(game->mlx.ptr, game->mlx.win, 170, 70, 0xFFFFFF,
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

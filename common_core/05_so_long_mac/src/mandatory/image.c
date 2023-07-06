/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:55:52 by Manny             #+#    #+#             */
/*   Updated: 2022/12/12 00:41:00 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	put_img(int row, int col, t_map *map, t_mlx mlx)
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

void	img_to_win(t_game *game)
{
	int	row;
	int	col;

	game->map.items_to_collect = 0;
	row = 0;
	while (row < game->map.height)
	{
		col = 0;
		while (col < game->map.width)
		{
			put_img(row, col, &(game->map), game->mlx);
			col++;
		}
		row++;
	}
}

void	img_init(t_mlx *mlx, t_img *img)
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
}

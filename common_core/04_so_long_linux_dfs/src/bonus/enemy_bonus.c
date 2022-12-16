/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:57:11 by Manny             #+#    #+#             */
/*   Updated: 2022/12/17 01:28:35 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	game_lose_bonus(t_game *game)
{
	free_map_data(&(game->map));
	ft_putstr_fd("You lost!\n", 1);
	exit (EXIT_SUCCESS);
}

void	put_enemy_bonus(t_map *map)
{
	int	row;
	int	col;

	srand(time(NULL));
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if (map->map_data[row][col] == '0' && rand() % (42 / 2) == 0)
				map->map_data[row][col] = 'N';
			col++;
		}
		row++;
	}
}

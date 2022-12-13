/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:57:11 by Manny             #+#    #+#             */
/*   Updated: 2022/12/05 01:44:20 by Manny            ###   ########.fr       */
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
	int	i;
	int	j;

	srand(time(NULL));
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_data[i][j] == '0' && rand() % (42 / 2) == 0)
				map->map_data[i][j] = 'N';
			j++;
		}
		i++;
	}
}

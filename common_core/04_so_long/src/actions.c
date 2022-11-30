/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:33:18 by Manny             #+#    #+#             */
/*   Updated: 2022/11/30 18:30:28 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map_data(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map_data[i]);
		i++;
	}
	free(map->map_data);
}

int	game_win(t_game *game)
{
	free_map_data(&(game->map));
	ft_putstr_fd("YOU WIN!\n", 1);
	exit (EXIT_SUCCESS);
}

int	game_close(t_game *game)
{
	free_map_data(&(game->map));
	exit (EXIT_SUCCESS);
}

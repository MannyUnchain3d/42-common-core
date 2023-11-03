/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:54:58 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/03 12:25:14 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Initializes the player's direction and plane
 * based on their initial facing direction.
 * Facing North: dir_x and dir_y are set to 0 and -1 to face upward plane_x and
 * plane_y are set to 0.66 and 0, setting a field of view of 66 degrees.
 * Facing South: dir_x and dir_y are set to 0 and 1  to face downward.
 * plane_x and plane_y are set to -0.66 and 0 flipping the field of view
 * since the player is facing the opposite direction compared to north.
 * If the player is not facing north or south, the function does nothing. */
static void	init_player_north_south(t_player *player)
{
	if (player->dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (player->dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else
		return ;
}

static void	init_player_west_east(t_player *player)
{
	if (player->dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (player->dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else
		return ;
}

void	init_player_dir(t_data *data)
{
	init_player_north_south(&data->player);
	init_player_west_east(&data->player);
}

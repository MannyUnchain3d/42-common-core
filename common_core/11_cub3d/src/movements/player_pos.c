/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:38:33 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/01 17:36:28 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	valid_pos_wall_collision(t_data *data, double x, double y)
{
	if (data->map[(int)y][(int)x] == '0')
		return (true);
	return (false);
}

static bool	valid_pos_in_map(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->map_info.width - 1.25)
		return (false);
	if (y < 0.25 || y >= data->map_info.height - 0.25)
		return (false);
	return (true);
}

static bool	valid_pos(t_data *data, double x, double y)
{
	if (!BONUS && valid_pos_in_map(data, x, y))
		return (true);
	if (BONUS && valid_pos_wall_collision(data, x, y))
		return (true);
	return (false);
}

int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (valid_pos(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (valid_pos(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:15:51 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/03 12:42:23 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Rotates the player's direction and plane vectors based on the
 * specified rotation angle `rot_speed`.
 * 1. Creates a pointer to the player data.
 * 2. Stores the original `x` component of the vectors.
 * 3. Applies the 2D rotation formulae to the direction and plane vectors.
 * 4. Returns `1` to indicate successful execution. */
static int	rotate_left_right(t_data *data, double rot_speed)
{
	t_player	*p;
	double		tmp_x;

	p = &data->player;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rot_speed) - p->dir_y * sin(rot_speed);
	p->dir_y = tmp_x * sin(rot_speed) + p->dir_y * cos(rot_speed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rot_speed) - p->plane_y * sin(rot_speed);
	p->plane_y = tmp_x * sin(rot_speed) + p->plane_y * cos(rot_speed);
	return (1);
}

int	rotate_player(t_data *data, double rot_dir)
{
	int		moved;
	double	rot_speed;

	moved = 0;
	rot_speed = rot_dir * ROT_SPEED;
	moved += rotate_left_right(data, rot_speed);
	return (moved);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:49:04 by etetopat          #+#    #+#             */
/*   Updated: 2023/10/03 19:54:36 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		quit_cub3d(data);
	if (key == XK_Left)
		data->player.rotate -= 1;
	if (key == XK_Right)
		data->player.rotate += 1;
	if (key == XK_w || key == XK_Up)
		data->player.move_y = 1;
	if (key == XK_a)
		data->player.move_x = -1;
	if (key == XK_s || key == XK_Down)
		data->player.move_y = -1;
	if (key == XK_d)
		data->player.move_x = 1;
	return (0);
}

static int	key_release_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		quit_cub3d(data);
	if (key == XK_Left && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (key == XK_Right && data->player.rotate >= -1)
		data->player.rotate = 0;
	if ((key == XK_w || key == XK_Up) && data->player.move_y == 1)
		data->player.move_y = 0;
	if (key == XK_a && data->player.move_x == -1)
		data->player.move_x = 0;
	if ((key == XK_s || key == XK_Down) && data->player.move_y == -1)
		data->player.move_y = 0;
	if (key == XK_d && data->player.move_x == 1)
		data->player.move_x = 0;
	return (0);
}

//MOUSE BONUS IF ENOUGH TIME
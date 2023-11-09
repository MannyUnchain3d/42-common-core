/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:49:04 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/09 14:11:10 by etetopat         ###   ########.fr       */
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
	if ((key == XK_w || key == XK_Up) && data->player.move_y == 1)
		data->player.move_y = 0;
	if (key == XK_a && data->player.move_x == -1)
		data->player.move_x += 1;
	if ((key == XK_s || key == XK_Down) && data->player.move_y == -1)
		data->player.move_y = 0;
	if (key == XK_d && data->player.move_x == 1)
		data->player.move_x -= 1;
	if (key == XK_Left && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (key == XK_Right && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (0);
}

static void	wrap_mouse_position(t_data *data, int x, int y)
{
	if (x > data->win_width - DIST_EDGE_MOUSE_WRAP)
	{
		x = DIST_EDGE_MOUSE_WRAP;
		mlx_mouse_move(data->mlx, data->win, x, y);
	}
	if (x < DIST_EDGE_MOUSE_WRAP)
	{
		x = data->win_width - DIST_EDGE_MOUSE_WRAP;
		mlx_mouse_move(data->mlx, data->win, x, y);
	}
}

static int	mouse_handler(int x, int y, t_data *data)
{
	static int	old_x = WIN_WIDTH / 2;

	wrap_mouse_position(data, x, y);
	if (x == old_x)
		return (0);
	else if (x < old_x)
		data->player.moved += rotate_player(data, -1);
	else if (x > old_x)
		data->player.moved += rotate_player(data, 1);
	old_x = x;
	return (0);
}

/* Sets up the hooks to listen for specific user input events.
 * 1. Closes the window: `quit_cub3d` function is called.
 * 2. Presses a key: `key_press_handler` function is called.
 * 3. Releases a key: `key_release_handler` function is called.
 * If the BONUS flag is set to true, an additional hook is set up
 * to call the `mouse_handler` function when the mouse is moved. */
void	listen_for_input(t_data *data)
{
	mlx_hook(data->win, ClientMessage, NoEventMask, quit_cub3d, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release_handler, data);
	if (BONUS)
		mlx_hook(data->win, MotionNotify, PointerMotionMask,
			mouse_handler, data);
}

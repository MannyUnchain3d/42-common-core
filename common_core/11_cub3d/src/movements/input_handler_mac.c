/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_mac.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:49:04 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/09 14:42:24 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press_handler(int key, t_data *data)
{
	if (key == 53)
		quit_cub3d(data);
	if (key == 123)
		data->player.rotate -= 1;
	if (key == 124)
		data->player.rotate += 1;
	if (key == 13 || key == 126)
		data->player.move_y = 1;
	if (key == 0)
		data->player.move_x = -1;
	if (key == 1 || key == 125)
		data->player.move_y = -1;
	if (key == 2)
		data->player.move_x = 1;
	return (0);
}

static int	key_release_handler(int key, t_data *data)
{
	if (key == 53)
		quit_cub3d(data);
	if ((key == 13 || key == 126) && data->player.move_y == 1)
		data->player.move_y = 0;
	if (key == 0 && data->player.move_x == -1)
		data->player.move_x += 1;
	if ((key == 1 || key == 125) && data->player.move_y == -1)
		data->player.move_y = 0;
	if (key == 2 && data->player.move_x == 1)
		data->player.move_x -= 1;
	if (key == 123 && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (key == 124 && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (0);
}

static void	wrap_mouse_position(t_data *data, int x)
{
	if (x > data->win_width - DIST_EDGE_MOUSE_WRAP)
	{
		x = DIST_EDGE_MOUSE_WRAP;
		mlx_mouse_move(data->win, x, data->win_height / 2);
	}
	if (x < DIST_EDGE_MOUSE_WRAP)
	{
		x = data->win_width - DIST_EDGE_MOUSE_WRAP;
		mlx_mouse_move(data->win, x, data->win_height / 2);
	}
}

static int	mouse_handler(int x, int y, t_data *data)
{
	static int	old_x = WIN_WIDTH / 2;

	(void)y;
	wrap_mouse_position(data, x);
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
	mlx_hook(data->win, 17, 0L, quit_cub3d, data);
	mlx_hook(data->win, 2, 0, key_press_handler, data);
	mlx_hook(data->win, 3, 0, key_release_handler, data);
	if (BONUS)
		mlx_hook(data->win, 6, 0, mouse_handler, data);
}

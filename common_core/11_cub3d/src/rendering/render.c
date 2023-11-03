/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:04:50 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/03 16:57:05 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Sets a pixel color in the frame image at the specified coordinates.
 * 1. If the color value at (x, y) in the texels array is greater than 0,
 * set the pixel color to this value.
 * 2. If y-coordinate is in the upper half of the window,
 * set the pixel color to the ceiling color.
 * 3. If y-coordinate is in the lower half but not the bottom row,
 * set the pixel color to the floor color. */
static void	set_frame_image_pixel(t_data *data, t_img *img, int x, int y)
{
	if (data->texels[y][x] > 0)
		set_image_pixel(img, x, y, data->texels[y][x]);
	else if (y < data->win_height / 2)
		set_image_pixel(img, x, y, data->tex_info.ceiling_hex);
	else if (y < data->win_height - 1)
		set_image_pixel(img, x, y, data->tex_info.floor_hex);
}

/* Renders a single frame to the window.
 * 1. Initializes an image structure to hold the frame data.
 * 2. Iterates through each pixel in the window
 * by nested loops over y and x coordinates.
 * 3. Calls set_frame_image_pixel to determine the color of each pixel.
 * 4. Displays the image in the window using mlx_put_image_to_window.
 * 5. Destroys the image to free the memory for the next frame.*/
static void	render_frame(t_data *data)
{
	t_img	img;
	int		x;
	int		y;

	img.img = NULL;
	init_img(data, &img, data->win_width, data->win_height);
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			set_frame_image_pixel(data, &img, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, img.img, 0, 0);
	mlx_destroy_image(data->mlx, img.img);
}

static void	render_raycast(t_data *data)
{
	init_texels(data);
	init_ray(&data->ray);
	raycasting(&data->player, data);
	render_frame(data);
}

/* I separate the raycast rendering to add minimap rendering later or never...*/
void	render_images(t_data *data)
{
	render_raycast(data);
}

int	render(t_data *data)
{
	data->player.moved += move_player(data);
	if (data->player.moved == 0)
		return (0);
	render_images(data);
	return (0);
}

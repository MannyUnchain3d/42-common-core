/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:04:50 by etetopat          #+#    #+#             */
/*   Updated: 2023/10/03 16:54:59 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_frame_image_pixel(t_data *data, t_img *img, int x, int y)
{
	if (data->texels[y][x] > 0)
		set_image_pixel(img, x, y, data->texels[y][x]);
	else if (y < data->win_height / 2)
		set_image_pixel(img, x, y, data->tex_info.ceiling_hex);
	else
		set_image_pixel(img, x, y, data->tex_info.floor_hex);
}

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

void	render_images(t_data *data)
{
	render_raycast(data);
	if (BONUS)
		render_minimap(data);
}

int	render(t_data *data)
{
	data->player.moved += move_player(data);
	if (data->player.moved == 0)
		return (0);
	render_images(data);
	return (0);
}

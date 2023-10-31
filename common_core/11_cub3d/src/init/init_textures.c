/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:28:27 by etetopat          #+#    #+#             */
/*   Updated: 2023/10/26 17:30:00 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_tex_img(data, &tmp, path);
	buffer = ft_calloc(1, sizeof * buffer * data->tex_info.size
			* data->tex_info.size);
	if (!buffer)
		clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
	y = 0;
	while (y < data->tex_info.size)
	{
		x = 0;
		while (x < data->tex_info.size)
		{
			buffer[y * data->tex_info.size + x]
				= tmp.addr[y * data->tex_info.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
	data->textures[NORTH] = xpm_to_img(data, data->tex_info.north);
	data->textures[SOUTH] = xpm_to_img(data, data->tex_info.south);
	data->textures[WEST] = xpm_to_img(data, data->tex_info.west);
	data->textures[EAST] = xpm_to_img(data, data->tex_info.east);
}

void	init_tex_info(t_tex_info *tex)
{
	tex->north = NULL;
	tex->south = NULL;
	tex->west = NULL;
	tex->east = NULL;
	tex->ceiling = 0;
	tex->floor = 0;
	tex->ceiling_hex = 0x000000;
	tex->floor_hex = 0x000000;
	tex->size = TEX_SIZE;
	tex->x = 0;
	tex->y = 0;
	tex->pos = 0;
	tex->step = 0;
}

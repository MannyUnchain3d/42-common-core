/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:28:27 by etetopat          #+#    #+#             */
/*   Updated: 2023/08/29 21:17:48 by etetopat         ###   ########.fr       */
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
	buffer = ft_calloc(1, sizeof(int) * (data->tex_info.size
				* data->tex_info.size));
	if (!buffer)
		clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
	y = 0;
	while (y < data->tex_info.size)
	{
		x = 0;
		while (y < data->tex_info.size)
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

void	init_tex_info(t_tex_info *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->ceiling = 0;
	textures->floor = 0;
	textures->ceiling_hex = 0x000000;
	textures->floor_hex = 0x000000;
	textures->size = TEX_SIZE;
	textures->x = 0;
	textures->y = 0;
	textures->pos = 0;
	textures->step = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:32:19 by etetopat          #+#    #+#             */
/*   Updated: 2023/10/17 16:52:04 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (err_msg_nb(rgb[i], ERR_TEX_RGB, FAILURE));
		i++;
	}
	return (SUCCESS);
}

static unsigned long	rgb_to_hex(int *rgb)
{
	unsigned long	hex;

	hex = 0;
	hex += rgb[0] * 256 * 256;
	hex += rgb[1] * 256;
	hex += rgb[2];
	return (hex);
}

int	check_textures(t_data *data, t_tex_info *tex)
{
	if (!tex->north || !tex->south || !tex->west || !tex->east)
		return (err_msg(data->map_info.path, ERR_TEX_MISSING, FAILURE));
	if (!tex->ceiling || !tex->floor)
		return (err_msg(data->map_info.path, ERR_TEX_COLOR, FAILURE));
	if (check_file(tex->north, false) == FAILURE
		|| check_file(tex->south, false) == FAILURE
		|| check_file(tex->west, false) == FAILURE
		|| check_file(tex->east, false) == FAILURE
		|| check_rgb(tex->ceiling) == FAILURE
		|| check_rgb(tex->floor) == FAILURE)
		return (FAILURE);
	tex->ceiling_hex = rgb_to_hex(tex->ceiling);
	tex->floor_hex = rgb_to_hex(tex->floor);
	return (SUCCESS);
}

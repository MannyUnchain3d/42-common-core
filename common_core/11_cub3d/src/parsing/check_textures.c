/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:32:19 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/03 12:58:51 by Manny            ###   ########.fr       */
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

/* Converts an RGB color value to a hexadecimal color value.
 * 1. Initializes a variable `hex` to store the hexadecimal value.
 * 2. Multiplies the red value by 256^2, the green value by 256,
 * and adds them along with the blue value to `hex`. (bit shifting)
 * Example for red = 255, green = 0, blue = 0:
 * hex = 255 * 256^2 + 0 * 256 + 0 = 16711680
 * 16711680 is the hexadecimal value for red (0xFF0000).
 * 3. Returns the hexadecimal color value.
 */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:14:24 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/03 17:08:09 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Initializes the texels array for storing texture pixel colors.
 * 1. Frees previous texels array if it exists.
 * 2. Allocates memory for the new texels array based on window dimensions.
 * 3. Iterates through each row of the texels array:
 *    - Allocates memory for each row based on window width.
 *    - Exits with an error message if memory allocation fails. */
void	init_texels(t_data *data)
{
	int	i;

	if (data->texels)
		free_tab((void **)data->texels);
	data->texels = ft_calloc(data->win_height + 1, sizeof * data->texels);
	if (!data->texels)
		clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
	i = 0;
	while (i < data->win_height)
	{
		data->texels[i] = ft_calloc(data->win_width + 1, sizeof * data->texels);
		if (!data->texels[i])
			clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
		i++;
	}
}

/* Determines the texture index based on the ray's hit side and direction. */
static void	get_tex_index(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->tex_info.index = WEST;
		else
			data->tex_info.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->tex_info.index = SOUTH;
		else
			data->tex_info.index = NORTH;
	}
}

/* Updates texel values based on raycast results and texture data.
 * 1. Sets the texture index based on ray's hit side and direction.
 * 2. Calculates initial texture coordinates (tex->x, tex->y).
 * 3. If the ray hits a wall facing west or south,
 * inverts the x-coordinate of the texture.
 * 4. Sets texture step based on wall slice height and texture size.
 * 5. Init texture position based on where wall slice starts to be drawn.
 * 6. Loops through each pixel in wall slice:
 * - Computes texture y-coordinate.
 * - Retrieves color from texture based on texture coordinates.
 * - Darkens color if texture is for north or east facing wall. (shadow effect)
 * - Updates texel value in data->texels array if color is non-zero. */
void	update_texels(t_data *data, t_tex_info *tex, t_ray *ray, int x)
{
	int	y;
	int	color;

	get_tex_index(data, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - data->win_height / 2
			+ ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = data->textures[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->texels[y][x] = color;
		y++;
	}
}

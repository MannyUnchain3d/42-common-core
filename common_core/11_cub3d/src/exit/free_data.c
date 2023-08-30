/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:18:34 by etetopat          #+#    #+#             */
/*   Updated: 2023/08/30 23:01:17 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

static void	free_tex_info(t_tex_info *tex_info)
{
	if (tex_info->north)
		free(tex_info->north);
	if (tex_info->south)
		free(tex_info->south);
	if (tex_info->west)
		free(tex_info->west);
	if (tex_info->east)
		free(tex_info->east);
	if (tex_info->floor)
		free(tex_info->floor);
	if (tex_info->ceiling)
		free(tex_info->ceiling);
}

static void	free_map(t_data *data)
{
	if (data->map_info.fd > 0)
		close(data->map_info.fd);
	if (data->map_info.file)
		free_tab((void **)data->map_info.file);
	if (data->map)
		free_tab((void **)data->map);
}

int	free_data(t_data *data)
{
	if (data->textures)
		free_tab((void **)data->textures);
	if (data->texels)
		free_tab((void **)data->texels);
	free_tex_info(&data->tex_info);
	free_map(data);
	return (FAILURE);
}

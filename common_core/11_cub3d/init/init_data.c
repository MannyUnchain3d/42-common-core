/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:17:35 by etetopat          #+#    #+#             */
/*   Updated: 2023/08/22 16:35:51 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_img(t_img *img)
{
	ft_memset(img, 0, sizeof(t_img));
}

void	init_ray(t_ray *ray)
{
	ft_memset(ray, 0, sizeof(t_ray));
}

void	init_map_info(t_map_info *map_info)
{
	ft_memset(map_info, 0, sizeof(t_map_info));
}

void	init_player(t_player *player)
{
	ft_memset(player, 0, sizeof(t_player));
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	init_player(&data->player);
	init_tex_info(&data->tex_info);
	data->map = NULL;
	init_map_info(&data->map_info);
	init_img(&data->minimap);
	data->texels = NULL;
	data->textures = NULL;
}

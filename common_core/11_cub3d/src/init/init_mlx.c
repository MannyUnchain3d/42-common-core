/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:36:21 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/09 14:10:27 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_img(t_data *data, t_img *img, int width, int height)
{
	init_clean_img(img);
	img->img = mlx_new_image(data->mlx, width, height);
	if (img->img == NULL)
		clean_exit(data, err_msg("mlx", ERR_MLX_IMG, 1));
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
	return ;
}

void	init_tex_img(t_data *data, t_img *img, char *path)
{
	init_clean_img(img);
	img->img = mlx_xpm_file_to_image(data->mlx, path, &data->tex_info.size,
			&data->tex_info.size);
	if (img->img == NULL)
		clean_exit(data, err_msg("mlx", ERR_MLX_IMG, 1));
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
	return ;
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		clean_exit(data, err_msg("mlx", ERR_MLX_START, 1));
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!data->win)
		clean_exit(data, err_msg("mlx", ERR_MLX_WIN, 1));
	if (BONUS)
		mlx_mouse_move(data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return ;
}

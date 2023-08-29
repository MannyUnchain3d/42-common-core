/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:32:18 by etetopat          #+#    #+#             */
/*   Updated: 2023/08/29 22:51:47 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_elements(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	data->player.dir = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			while (map_tab[i][j] == ' ' || map_tab[i][j] == '\t'
				|| map_tab[i][j] == '\r' || map_tab[i][j] == '\v'
				|| map_tab[i][j] == '\f')
				j++;
			if (!(ft_strchr("01NSWE", map_tab[i][j])))
				return (err_msg(data->map_info.path, ERR_CHAR, FAILURE));
			if (ft_strchr("NSWE", map_tab[i][j]) && data->player.dir != 0)
				return (err_msg(data->map_info.path, ERR_MAX_PLAYER, FAILURE));
			if (ft_strchr("NSWE", map_tab[i][j]) && data->player.dir == 0)
				data->player.dir = map_tab[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}


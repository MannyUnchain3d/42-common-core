/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:52:49 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/09 19:34:33 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player_pos(t_data *data, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_space(map[i][j]))
				j++;
			else if (map[i][j] == 'N' || map[i][j] == 'S' || \
			map[i][j] == 'W' || map[i][j] == 'E')
			{
				data->player.move_x = j;
				data->player.move_y = i;
				return ;
			}
		}
	}
	data->player.move_x = -1;
	data->player.move_y = -1;
}

static bool	check_wall(int x, int y, char **map)
{
	if (map[y][x - 1] != '1' && map[y][x - 1] != '0')
		return (false);
	else if (map[y][x + 1] != '1' && map[y][x + 1] != '0')
		return (false);
	else if (map[y - 1][x] != '1' && map[y - 1][x] != '0')
		return (false);
	else if (map[y + 1][x] != '1' && map[y + 1][x] != '0')
		return (false);
	return (true);
}

void	flood_fill(int x, int y, char **map, t_data *data)
{
	int	col;
	int	row;

	col = ft_strlen(map[y]) - 1;
	row = data->map_info.height;
	if (map == NULL)
		return ;
	if (x < 0 || y < 0 || y > row || x > col || map[y][x] == '1')
		return ;
	if (map[y][x] == '0' && check_wall(x, y, map) == false)
		data->map_info.error++;
	map[y][x] = '1';
	flood_fill(x - 1, y, map, data);
	flood_fill(x, y - 1, map, data);
	flood_fill(x + 1, y, map, data);
	flood_fill(x, y + 1, map, data);
}

int	check_border(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' && check_wall(j, i, map) == false)
				return (0);
		}
	}
	return (1);
}

int	check_map_fah(t_data *data, char **map_tab)
{
	char	**new_map;
	int		x;
	int		y;

	new_map = fah_dup2stars(map_tab);
	get_player_pos(data, map_tab);
	data->map_info.error = 0;
	x = data->player.move_x;
	y = data->player.move_y;
	if (x < 0 || y < 0)
		return (del_2stars(new_map), FAILURE);
	flood_fill(x, y, new_map, data);
	if (check_border(new_map) == 0)
		return (del_2stars(new_map), FAILURE);
	if (data->map_info.error != 0)
		return (del_2stars(new_map), FAILURE);
	return (del_2stars(new_map), SUCCESS);
}

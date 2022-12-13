/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:46:02 by Manny             #+#    #+#             */
/*   Updated: 2022/12/12 18:42:03 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	rev_dfs(t_map *map, int row, int col)
{
	if (map->map_data[row][col] != 'v' && map->map_data[row][col] != 'C')
		return ;
	else
	{
		if (map->map_data[row][col] == 'v')
			map->map_data[row][col] = '0';
		rev_dfs(map, row + 1, col);
		rev_dfs(map, row - 1, col);
		rev_dfs(map, row, col + 1);
		rev_dfs(map, row, col - 1);
	}
	return ;
}

void	dfs(t_map *map, int row, int col)
{
	if (map->map_data[row][col] != '0' && map->map_data[row][col] != 'C')
		return ;
	if (map->map_data[row][col] == '0')
		map->map_data[row][col] = 'v';
	dfs(map, row + 1, col);
	dfs(map, row - 1, col);
	dfs(map, row, col + 1);
	dfs(map, row, col - 1);
}

int	check_collectibles(t_map *map)
{
	int	row;
	int	col;

	row = -1;
	while (map->map_data[++row])
	{
		col = -1;
		while (map->map_data[row][++col])
		{
			if (map->map_data[row][col] == 'C')
			{
				if ((map->map_data[row + 1][col] == '0'
					|| map->map_data[row + 1][col] == '1')
					&& (map->map_data[row - 1][col] == '0'
					|| map->map_data[row - 1][col] == '1')
					&& (map->map_data[row][col + 1] == '0'
					|| map->map_data[row][col + 1] == '1')
					&& (map->map_data[row][col - 1] == '0'
					|| map->map_data[row][col - 1] == '1'))
					return (1);
			}
		}
	}
	return (0);
}

int	is_path(t_map *map)
{
	int	row;
	int	col;

	row = -1;
	while (map->map_data[++row])
	{
		col = -1;
		while (map->map_data[row][++col])
		{
			if (map->map_data[row][col] == 'E')
			{
				if (map->map_data[row +1][col] == 'v'
					|| map->map_data[row - 1][col] == 'v'
					|| map->map_data[row][col + 1] == 'v'
					|| map->map_data[row][col - 1] == 'v')
					return (0);
				if (map->map_data[row +1][col] == 'C'
					|| map->map_data[row - 1][col] == 'C'
					|| map->map_data[row][col + 1] == 'C'
					|| map->map_data[row][col - 1] == 'C')
					return (0);
			}
		}
	}
	return (1);
}

void	flood_fill(t_map *map)
{
	int	row;
	int	col;

	find_player(map, &row, &col);
	map->map_data[row][col] = '0';
	dfs(map, row, col);
	if (check_collectibles(map) == 1 || is_path(map) == 1)
		display_error_exit(MAP_PATH_ERR);
	rev_dfs(map, row, col);
	map->map_data[row][col] = 'P';
}

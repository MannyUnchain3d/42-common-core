/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:46:02 by Manny             #+#    #+#             */
/*   Updated: 2022/12/19 20:06:51 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	dfs(char **new_map, int row, int col, t_map *map)
{
	if (row < 0 || col < 0 || row >= map->height - 1 || col >= map->width - 1)
		return ;
	if (new_map[row][col] == '1' || new_map[row][col] == 'v'
			|| new_map[row][col] == '\0' || new_map[row][col] == 'N')
		return ;
	if (new_map[row][col] == 'C')
		map->collectible++;
	if (new_map[row][col] == 'E')
	{
		map->exit = 1;
		return ;
	}
	new_map[row][col] = 'v';
	dfs(new_map, row + 1, col, map);
	dfs(new_map, row - 1, col, map);
	dfs(new_map, row, col + 1, map);
	dfs(new_map, row, col - 1, map);
}

char	**map_dup(t_map *map)
{
	int		i;
	char	**new_map;

	i = 0;
	new_map = malloc(sizeof(char *) * (map->height + 1));
	if (new_map == NULL)
		display_error_exit(map, MALLOC_ERR);
	new_map[map->height] = NULL;
	while (i < map->height)
	{
		new_map[i] = ft_strdup(map->map_data[i]);
		i++;
	}
	return (new_map);
}

void	flood_fill(t_map *map)
{
	int				row;
	int				col;
	char			**new_map;

	row = 0;
	col = 0;
	while (map->map_data[row] && map->map_data[row][col] != 'P')
	{
		col = 0;
		while (map->map_data[row][col] && map->map_data[row][col] != 'P')
			col++;
		if (map->map_data[row][col] == 'P')
			break ;
		row++;
	}
	new_map = map_dup(map);
	map->collectible = 0;
	map->exit = 0;
	dfs(new_map, row, col, map);
	if (map->collectible <= 0 || map->exit != 1
		|| map->collectible != map->cc_count)
		display_error_exit(map, MAP_PATH_ERR);
	free_map(new_map);
}

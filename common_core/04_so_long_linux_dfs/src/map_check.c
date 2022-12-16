/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:33:35 by Manny             #+#    #+#             */
/*   Updated: 2022/12/17 00:20:55 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	symbols_init(t_map_checker *checker)
{
	checker->start = 0;
	checker->exits = 0;
	checker->collectibles = 0;
}

static void	count_symbols(t_map_checker *checker, char symbols)
{
	if (symbols == 'P')
		checker->start++;
	else if (symbols == 'C')
		checker->collectibles++;
	else if (symbols == 'E')
		checker->exits++;
}

static void	check_content_size(t_map *map, int row, int col)
{
	if (map->map_data[row][col] != '0' && map->map_data[row][col] != '1'
		&& map->map_data[row][col] != 'P' && map->map_data[row][col] != 'C'
		&& map->map_data[row][col] != 'E')
		display_error_exit(map, WRONG_CHAR_ERR);
	if (row == 0 || col == 0 || col == map->width - 1 || row == map->height - 1)
		if (map->map_data[row][col] != '1')
			display_error_exit(map, MAP_WALLS_ERR);
}

void	map_symbols_checker(t_map *map)
{
	int				row;
	int				col;
	t_map_checker	checker;

	symbols_init(&checker);
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			count_symbols(&checker, map->map_data[row][col]);
			check_content_size(map, row, col);
			col++;
		}
		row++;
	}
	if (checker.exits * checker.collectibles == 0)
		display_error_exit(map, MAP_EXIT_ERR);
	if (checker.start != 1)
		display_error_exit(map, MAP_START_ERR);
	map->cc_count = checker.collectibles;
}

void	is_ber_file(t_map *map, char *filename)
{
	int	len;

	len = ft_strlen(filename, 0) - 1;
	if (filename[len - 3] != '.' || filename[len - 2] != 'b'
		|| filename[len - 1] != 'e' || filename[len] != 'r')
		display_error_exit(map, FILE_EXT_ERR);
}

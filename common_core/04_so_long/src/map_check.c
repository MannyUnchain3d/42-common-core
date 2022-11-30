/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:33:35 by Manny             #+#    #+#             */
/*   Updated: 2022/11/30 20:01:51 by Manny            ###   ########.fr       */
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

static void	check_content_size(t_map *map, int i, int j)
{
	if (map->map_data[i][j] != '0' && map->map_data[i][j] != '1'
		&& map->map_data[i][j] != 'P' && map->map_data[i][j] != 'C'
		&& map->map_data[i][j] != 'E')
		display_error_exit(WRONG_CHAR_ERR);
	if (i == 0 || j == 0 || j == map->width - 1 || i == map->height - 1)
		if (map->map_data[i][j] != '1')
			display_error_exit(MAP_WALLS_ERR);
}

void	map_symbols_checker(t_map *map)
{
	int				i;
	int				j;
	t_map_checker	checker;

	symbols_init(&checker);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			count_symbols(&checker, map->map_data[i][j]);
			check_content_size(map, i, j);
			j++;
		}
		i++;
	}
	if (checker.exits * checker.collectibles == 0)
		display_error_exit(MAP_EXIT_ERR);
	if (checker.start != 1)
		display_error_exit(MAP_START_ERR);
}

void	is_ber_file(char *filename)
{
	int	len;

	len = ft_strlen(filename, 0) - 1;
	if (filename[len - 3] != '.' || filename[len - 2] != 'b'
		|| filename[len - 1] != 'e' || filename[len] != 'r')
		display_error_exit(FILE_EXT_ERR);
}

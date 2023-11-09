/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:19:52 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/07 17:24:19 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_map_lines(t_data *data, char **file, int i)
{
	int	start_index;
	int	j;

	start_index = i;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t' || file[i][j] == '\r'
			|| file[i][j] == '\v' || file[i][j] == '\f')
			j++;
		if (file[i][j] != '1')
			break ;
		i++;
	}
	data->map_info.index_end_of_map = i;
	return (i - start_index);
}

/* Fills a 2D array `map_tab` with map data starting from a specified index.
 * 1. Determines the width of the map using `find_map_width`.
 * 2. Iterates through each line of the map (up to the map's height).
 * - Allocates memory for each row in `map_tab` based on the map's width.
 * - Checks for memory allocation failure and returns an error if necessary.
 * - Copies characters from the file to `map_tab` until a newline
 * or end of line is encountered.
 * - Fills any remaining characters in `map_tab` row with null characters ('\0')
 * to match the map's width.
 * - Increments the index to move to the next line in the file.
 * 3. Sets the last row of `map_tab` to NULL to indicate the end of the map data.
 * 4. Returns `SUCCESS` to indicate successful execution.
 */
static int	fill_map_tab(t_map_info *map_info, char **map_tab, int index)
{
	int	i;
	int	j;

	map_info->width = find_map_width(map_info, index);
	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		map_tab[i] = malloc(sizeof(char) * (map_info->width + 1));
		if (!map_tab[i])
			return (err_msg(NULL, ERR_MALLOC, FAILURE));
		while (map_info->file[index][j] && map_info->file[index][j] != '\n')
		{
			map_tab[i][j] = map_info->file[index][j];
			j++;
		}
		while (j < map_info->width)
			map_tab[i][j++] = '\0';
		i++;
		index++;
	}
	map_tab[i] = NULL;
	return (SUCCESS);
}

static int	get_map_info(t_data *data, char **file, int i)
{
	data->map_info.height = count_map_lines(data, file, i);
	data->map = malloc(sizeof(char *) * (data->map_info.height + 1));
	if (!data->map)
		return (err_msg(NULL, ERR_MALLOC, FAILURE));
	if (fill_map_tab(&data->map_info, data->map, i) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	create_map(t_data *data, char **file, int i)
{
	if (get_map_info(data, file, i) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

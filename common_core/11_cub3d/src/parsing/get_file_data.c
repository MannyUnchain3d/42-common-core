/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:17:02 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/03 14:12:05 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Extracts a file path from a given line starting from index `j`.
 * 1. Skips any leading whitespace characters from index `j`.
 * 2. Calculates the length of the file path
 * by finding the next whitespace or end of line.
 * 3. Allocates memory for `path` to store the extracted file path.
 *    - Returns NULL if memory allocation fails.
 * 4. Copies characters from `line` to `path` until a whitespace, tab,
 * or newline is encountered.
 * 5. Terminates `path` with a null character to form a valid string.
 * 6. Skips any trailing whitespace characters.
 * 7. Checks if there are any extra characters after the file path.
 *    - If found, frees `path` and sets it to NULL to indicate an error.
 * 8. Returns the extracted file path or NULL if an error occurs. */
static char	*get_tex_path(char *line, int j)
{
	int		i;
	int		len;
	char	*path;

	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	len = j;
	while (line[len] && (line[len] != ' ' && line[len] != '\t'))
		len++;
	path = malloc(sizeof(char) * (len - j + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[j] && (line[j] != ' ' && line[j] != '\t' && line[j] != '\n'))
		path[i++] = line[j++];
	path[i] = '\0';
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

static int	fill_direction_tex(t_tex_info *tex, char *line, int j)
{
	if (line[j + 2] && ft_isprint(line[j + 2]))
		return (ERROR);
	if (line[j] == 'N' && line[j + 1] == 'O' && !(tex->north))
		tex->north = get_tex_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(tex->south))
		tex->south = get_tex_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(tex->west))
		tex->west = get_tex_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(tex->east))
		tex->east = get_tex_path(line, j + 2);
	else
		return (ERROR);
	return (SUCCESS);
}

/* Skips over whitespace characters and processes map data based.
 * 1. Skips any leading whitespace characters in the current line.
 * 2. Checks if the first non-whitespace character is printable and not a digit:
 * - If the next character is also printable and not a digit,
 * attempts to process the characters as texture or direction information.
 * - If there's no following character or it's a whitespace or a digit,
 * attempts to process the characters as color information.
 * 3. If the first non-whitespace character is a digit,
 * attempts to process the map starting from the current line.  */
static int	ignore_ws_get_data(t_data *data, char **map, int i, int j)
{
	while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
		j++;
	if (ft_isprint(map[i][j]) && !ft_isdigit(map[i][j]))
	{
		if (map[i][j + 1] && ft_isprint(map[i][j + 1])
			&& !ft_isdigit(map[i][j]))
		{
			if (fill_direction_tex(&data->tex_info, map[i], j) == ERROR)
				return (err_msg(data->map_info.path, ERR_TEX_INVALID, FAILURE));
			return (BREAK);
		}
		else
		{
			if (fill_color_textures(data, &data->tex_info, map[i], j) == ERROR)
				return (FAILURE);
			return (BREAK);
		}
	}
	else if (ft_isdigit(map[i][j]))
	{
		if (create_map(data, map, i) == FAILURE)
			return (err_msg(data->map_info.path, ERR_MAP_INVALID, FAILURE));
		return (SUCCESS);
	}
	return (CONTINUE);
}

int	get_file_data(t_data *data, char **map)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ret = ignore_ws_get_data(data, map, i, j);
			if (ret == BREAK)
				break ;
			else if (ret == FAILURE)
				return (FAILURE);
			else if (ret == SUCCESS)
				return (SUCCESS);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

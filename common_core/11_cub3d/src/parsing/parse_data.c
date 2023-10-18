/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:16:08 by Manny             #+#    #+#             */
/*   Updated: 2023/10/18 21:01:45 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_nb_of_lines(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		err_msg(path, strerror(errno), errno);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

static void	fill_tab(int row, int col, int i, t_data *data)
{
	char	*line;

	line = get_next_line(data->map_info.fd);
	while (line != NULL)
	{
		data->map_info.file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map_info.file[row])
		{
			err_msg(NULL, ERR_MALLOC, 0);
			return (free_tab((void **)data->map_info.file));
		}
		while (line[i] != '\0')
			data->map_info.file[row][col++] = line[i++];
		data->map_info.file[row++][col] = '\0';
		col = 0;
		i = 0;
		free(line);
		line = get_next_line(data->map_info.fd);
	}
	data->map_info.file[row] = NULL;
}

void	parse_data(char *path, t_data *data)
{
	int		i;
	int		row;
	size_t	col;

	i = 0;
	row = 0;
	col = 0;
	data->map_info.line_count = get_nb_of_lines(path);
	data->map_info.path = path;
	data->map_info.file = ft_calloc(data->map_info.line_count
			+ 1, sizeof(char *));
	if (!data->map_info.file)
	{
		err_msg(NULL, ERR_MALLOC, 0);
		return ;
	}
	data->map_info.fd = open(path, O_RDONLY);
	if (data->map_info.fd < 0)
		err_msg(path, strerror(errno), FAILURE);
	else
	{
		fill_tab(row, col, i, data);
		close(data->map_info.fd);
	}
}

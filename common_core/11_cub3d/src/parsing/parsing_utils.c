/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:58:13 by etetopat          #+#    #+#             */
/*   Updated: 2023/10/24 17:28:58 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_whitespace(char c)
{
	if (c != ' ' && c != '\t' && c != '\r' && c != '\n'
		&& c != '\v' && c != '\f')
		return (FAILURE);
	else
		return (SUCCESS);
}

size_t	find_map_width(t_map_info *map, int i)
{
	size_t	longest_line;

	longest_line = ft_strlen(map->file[i]);
	while (map->file[i])
	{
		if (ft_strlen(map->file[i]) > longest_line)
			longest_line = ft_strlen(map->file[i]);
		i++;
	}
	return (longest_line);
}

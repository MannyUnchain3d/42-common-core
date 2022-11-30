/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:06:15 by etetopat          #+#    #+#             */
/*   Updated: 2022/11/29 20:38:49 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_before_newline(int fd, char *leftover)
{
	char	*buff;
	int		read_bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr_gnl(leftover, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		leftover = ft_strjoin_gnl(leftover, buff);
	}
	free(buff);
	return (leftover);
}

char	*ft_line_from_leftover(char *leftover)
{
	char	*line;
	int		i;

	i = 0;
	while (leftover[i] != '\n' && leftover[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (leftover[i] != '\n' && leftover[i] != '\0')
	{
		line[i] = leftover[i];
		i++;
	}
	if (leftover[i] == '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_trim_leftover(char *leftover)
{
	char	*new_leftover;
	int		i;
	int		j;

	i = 0;
	while (leftover[i] != '\n' && leftover[i] != '\0')
		i++;
	if (!leftover[i])
	{
		free(leftover);
		return (NULL);
	}
	new_leftover = (char *)malloc(sizeof(char) * (ft_strlen_gnl(leftover)
				- i + 1));
	if (!new_leftover)
		return (NULL);
	i++;
	j = 0;
	while (leftover[i] != '\0')
		new_leftover[j++] = leftover[i++];
	new_leftover[j] = '\0';
	free(leftover);
	return (new_leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = ft_read_before_newline(fd, leftover);
	if (!leftover)
		return (NULL);
	line = ft_line_from_leftover(leftover);
	leftover = ft_trim_leftover(leftover);
	return (line);
}

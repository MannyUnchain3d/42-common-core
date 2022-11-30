/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:17:13 by etetopat          #+#    #+#             */
/*   Updated: 2022/11/29 20:13:49 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	if (!s)
		return (0);
	if ((char)c == '\0')
		return ((char *)s);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strcpy_gnl(char *str, char *leftover)
{
	int	i;

	i = 0;
	while (leftover[i] != '\0')
	{
		str[i] = leftover[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strcat_gnl(char *str, char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (buff[j] != '\0')
	{
		str[i + j] = buff[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char *leftover, char *buff)
{
	char	*str;
	size_t	len;

	if (!leftover)
	{
		leftover = (char *)malloc(sizeof(char) * 1);
		leftover[0] = '\0';
	}
	if (!leftover || !buff)
		return (0);
	len = ft_strlen_gnl(leftover) + ft_strlen_gnl(buff);
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (0);
	if (leftover)
		ft_strcpy_gnl(str, leftover);
	ft_strcat_gnl(str, buff);
	free(leftover);
	return (str);
}

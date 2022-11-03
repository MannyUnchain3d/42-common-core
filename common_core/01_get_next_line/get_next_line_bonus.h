/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:16:50 by etetopat          #+#    #+#             */
/*   Updated: 2022/06/02 18:18:39 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s1);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*get_next_line(int fd);

# define OPEN_MAX 256

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:16:50 by etetopat          #+#    #+#             */
/*   Updated: 2022/11/29 20:46:09 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

char	*get_next_line(int fd);
char	*ft_read_before_newline(int fd, char *leftover);
char	*ft_line_from_leftover(char *leftover);
char	*ft_trim_leftover(char *leftover);
size_t	ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *leftover, char *buff);
char	*ft_strcat_gnl(char *str, char *buff);
char	*ft_strcpy_gnl(char *str, char *leftover);

#endif
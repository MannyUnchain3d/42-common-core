/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:14:29 by Manny             #+#    #+#             */
/*   Updated: 2023/07/24 05:44:43 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Function that searches for all paths in the environment, splits them,
 * tries each command path and returns the right one. */
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

/* Displays an error. */
void	error(char *filename, char *message)
{
	ft_putstr_fd("pipex: ", 2);
	if (filename && *filename)
	{
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	if (message && !ft_strncmp(message, "command not found", 17))
		exit(127);
	if (filename == NULL)
		exit(0);
	exit(EXIT_FAILURE);
}

/* Function that takes the command and send it to find_path
 * before executing it */
void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error(argv, "command not found");
	}
	if (execve(path, cmd, envp) == -1)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		free(path);
		error(argv, strerror(errno));
	}
}

/* Function that read input from the terminal and return line. */
int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		ret;
	char	c;

	i = 0;
	ret = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	ret = read(0, &c, 1);
	while (ret && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		ret = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (ret);
}

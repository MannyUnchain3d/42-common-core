/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_imp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <nicklaw@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:11:13 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/28 15:20:15 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	here_input(int fd, char *delimit, t_data *data);
static int	here_input2(int fd, char *delimit, t_data *data, char *buffer);

/* Handles heredoc processing for a command: creates a temporary file,
 * captures user input until a delimiter is encountered,
 * and assigns the input file descriptor.
 * Returns 0 on success or an error code if any step fails. */
static int	handle_heredoc(t_cmd *cmd, t_data *data, int name_sfx)
{
	int		here_fd;
	char	*delimit;
	char	*tmp;
	char	*name;

	tmp = ft_itoa(name_sfx);
	name = ft_strjoin(HEREDOC_NAME, tmp);
	free(tmp);
	tmp = ft_strjoin(cmd->io_fds->heredoc_delimiter[0], "\n");
	delimit = ft_strjoin(tmp, "\0");
	free (tmp);
	here_fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (here_fd < 0)
		return (here_error(name, delimit, 1));
	if (here_input(here_fd, delimit, data) == -1)
		return (here_error(name, delimit, 2));
	close(here_fd);
	here_fd = open(name, O_RDONLY);
	if (here_fd < 0)
		return (here_error(name, delimit, 2));
	free(name);
	free(delimit);
	cmd->io_fds->fd_in = here_fd;
	return (0);
}

int	heredoc_imp(t_cmd *cmd, t_data *data)
{
	int	i;

	i = 0;
	while (cmd)
	{
		if (cmd->io_fds->heredoc_delimiter[0])
			handle_heredoc(cmd, data, i++);
		cmd = cmd->next;
	}
	set_signals_noninteractive(data);
	return (0);
}

/* Read input user and write it to the specified file descriptor.
 * The input is terminated when the specified delimiter is encountered.
 * Returns 0 on succes, -1 on error, 2 if the delimiter is encountered. */
static int	here_input(int fd, char *delimit, t_data *data)
{
	char	*buffer;
	char	*tmp;

	while (1)
	{
		buffer = ft_calloc(10000, sizeof(char));
		if (!buffer)
			return (-1);
		rl_on_new_line();
		tmp = readline(">");
		if (!tmp)
			break ;
		ft_memcpy(buffer, tmp, ft_strlen(tmp));
		buffer[ft_strlen(tmp) + 1] = '\0';
		buffer[ft_strlen(tmp)] = '\n';
		free(tmp);
		if (here_input2(fd, delimit, data, buffer) == 2)
			break ;
	}
	free(buffer);
	return (0);
}

/* Processes a line of input captured from a here document,
 * performs environment variable expansion,
 * and writes the processed input to the specified file descriptor. */
static int	here_input2(int fd, char *delimit, t_data *data, char *buffer)
{
	if (!ft_strcmp(delimit, buffer))
		return (2);
	else
	{
		here_env(&buffer, data);
		ft_putstr_fd(buffer, fd);
	}
	free(buffer);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:41:03 by Manny             #+#    #+#             */
/*   Updated: 2023/07/03 16:08:58 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Child process creates a fork and a pipe, redirects the output inside a pipe,
 then closes the fd and executes the function.*/
void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

/* Function to make a child process reads from stdin using get_next_line,
 stops when it reaches the limiter, then redirects the output to a pipe. */
void	here_doc(char *limiter, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (argc < 6)
		usage();
	if (pipe(fd) == -1)
		error();
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if ((ft_strncmp(line, limiter, ft_strlen(limiter))) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

/* Main function runs the child processes with the right fds or displays 
 an error message if the arguments are wrong. It runs the here_doc function 
 if the "here_doc" string is passed in argv[1] */
int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fdin;
	int	fdout;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			fdout = open_fd(argv[argc - 1], 0);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			fdout = open_fd(argv[argc - 1], 1);
			fdin = open_fd(argv[1], 2);
			dup2(fdin, STDIN_FILENO);
		}
		while (i < argc - 2)
			child_process(argv[i++], envp);
		dup2(fdout, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
	usage();
}

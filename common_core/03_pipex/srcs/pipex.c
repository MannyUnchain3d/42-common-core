/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:13:03 by Manny             #+#    #+#             */
/*   Updated: 2022/11/08 20:27:03 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* Child process runs inside a fork, takes the fdin, redirects the output,
 inside a pipe and closes the fd and executes the function. */
void	child_process(char **argv, char **envp, int *fd)
{
	int	fdin;

	fdin = open(argv[1], O_RDONLY, 0777);
	if (fdin == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(fdin, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

/* Parent process takes data from the pipe, redirects the output for the fdout,
 closes the fd and executes the function */
void	parent_process(char **argv, char **envp, int *fd)
{
	int	fdout;

	fdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fdout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

/* Main function creates a pipe, forks the process, runs child and parent
 process, or displays error message if fork fails or arguments are wrong. */
int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_process(argv, envp, fd);
		parent_process(argv, envp, fd);
		waitpid(pid, NULL, 0);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}

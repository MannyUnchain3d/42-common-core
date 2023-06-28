/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:13:12 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/25 12:36:41 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Configures signal handling for interactive mode:
 * SIGINT (Ctrl+C) is handled by 'handle_sig'.
 * SIGQUIT (Ctrl+\) is ignored.
 * SA_RESTART flag is set to restart interrupted system calls.
 * Terminal attributes are restored to the parent process. */
void	set_signals_interactive(t_data *data)
{
	sigemptyset(&data->sigint.sa_mask);
	sigemptyset(&data->sigquit.sa_mask);
	data->sigint.sa_flags = SA_RESTART;
	data->sigquit.sa_flags = SA_RESTART;
	data->sigint.sa_handler = &handle_sig;
	data->sigquit.sa_handler = SIG_IGN;
	sigaction(SIGINT, &data->sigint, NULL);
	sigaction(SIGQUIT, &data->sigquit, NULL);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &data->parent);
}

/* Signal handler for SIGINT (Ctrl+C):
 * Prints a newline character to STDOUT_FILENO.
 * Resets the readline library state to start a new line.
 * Clears the current input line.
 * Redisplays the prompt. */
void	handle_sig(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	return ;
}

void	child_handle(int signo)
{
	if (signo == SIGINT)
		exit (130);
	if (signo == SIGQUIT)
		exit (131);
}

/* Configures signal handling for child processes:
 * SIGINT (Ctrl+C) and SIGQUIT (Ctrl+\) signals are handled by 'child_handle'.
 * The SA_RESTART flag is set to restart interrupted system calls.
 * Terminal attributes are set to match those of the child process.
 *
 * Note: The sigaction(SIGQUIT...) should be placed in 'execute_cmd()',
 * after the heredoc because SIGQUIT should not terminate during heredoc.
 * tcsetattr is used here to establish control input for the 'echo' command
 * that occurs within the heredoc.
 */
void	set_signals_child(t_data *data)
{
	sigemptyset(&data->sigint.sa_mask);
	sigemptyset(&data->sigquit.sa_mask);
	data->sigint.sa_flags = SA_RESTART;
	data->sigquit.sa_flags = SA_RESTART;
	data->sigint.sa_handler = &child_handle;
	data->sigquit.sa_handler = &child_handle;
	sigaction(SIGINT, &data->sigint, NULL);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &data->child);
}

/* Configures signal handling for non-interactive mode (parent process):
 * SIGINT (Ctrl+C) is ignored.
 * SA_RESTART flag is set to restart interrupted system calls. */
void	set_signals_noninteractive(t_data *data)
{
	sigemptyset(&data->sigint.sa_mask);
	data->sigint.sa_flags = SA_RESTART;
	data->sigint.sa_handler = SIG_IGN;
	sigaction(SIGINT, &data->sigint, NULL);
}

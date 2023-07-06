/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <nicklaw@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:30:03 by Manny             #+#    #+#             */
/*   Updated: 2023/06/27 17:55:36 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Parses the user input and executes the corresponding command.
 * Updates the last exit code based on the execution result.*/
static void	process_input(t_data *data)
{
	int	ret;

	ret = 99;
	ret = parse_user_input(data);
	if (ret == 1)
	{
		if (data->cmd->next || data->cmd->args[0])
			data->last_exit_code = execute(data);
		else
			data->last_exit_code = 0;
	}
	else if (ret == 88)
		data->last_exit_code = 258;
	else
		data->last_exit_code = 1;
}

/* Runs the minishell in interactive mode.
 * It repeatedly prompts the user for input, parses and executes the commands,
 * and handles signals appropriately. */
void	minishell_interactive(t_data *data)
{
	while (1)
	{
		set_signals_interactive(data);
		data->user_input = readline(PROMPT);
		if (!data->user_input)
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			data->last_exit_code = 130;
			return ;
		}
		if (data->user_input[0] == '\0')
			continue ;
		add_history(data->user_input);
		set_signals_noninteractive(data);
		process_input(data);
		heredoc_free(data);
		free_data(data, false, true);
		data->cmd = 0;
	}
}

/* Initializes the data structure, checks for the correct number of arguments,
 * and starts the minishell in interactive mode.
 * Exits with last command or exit status. */
int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac != 1)
	{
		ft_putendl_fd("minishell: no arguments required", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_memset(&data, 0, sizeof(t_data));
	if (!init_data(&data))
		exit_shell(NULL, EXIT_FAILURE);
	minishell_interactive(&data);
	exit_shell(&data, data.last_exit_code);
	return (0);
}

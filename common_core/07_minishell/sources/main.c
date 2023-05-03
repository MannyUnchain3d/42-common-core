/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:30:03 by Manny             #+#    #+#             */
/*   Updated: 2023/05/03 18:36:05 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Checks if their are any arguments passed to the program.
 * If there are, checks if they are valid: no args or -c and a command.
 * Returns true if valid, false with usage message if not. */
static bool args_check(t_data *data, int ac, char **av)
{
    if (ac != 1 && ac != 3)
        return (usage_message(false));
    if (ac == 3)
    {
        data->interactive = false;
        if (!av[1] || (av[1] && ft_strcmp(av[1], "-c") != 0))
            return (usage_message(false));
        else if (!av[2] || (av[2] && av[2][0] == '\0'))
            return (usage_message(false));
    }
    else
        data->interactive = true;
    return (true);
}

/* Runs parsing and execution in interactive mode, i.e. when minishell
 * is started without arguments and provides a prompt for user input. */
void minishell_interactive(t_data *data)
{
    while (1)
    {
        set_signals_interactive();
        data->user_input = readline(PROMPT);
        set_signals_noninteractive();
        if (parse_user_input(data) == true)
            g_last_exit_code = execute(data);
        else
            g_last_exit_code = 1;
        free_data(data, false);
    }
}

/* Runs parsing and execution in non-interactive mode, i.e. when minishell
 * is started with arguments and executes the command passed as argument. */
void minishell_noninteractive(t_data *data, char *arg)
{
	char     **user_inputs;
	int      i;

	user_inputs = ft_split(arg, ';');
	if (!user_inputs)
       exit_shell(data, EXIT_FAILURE);
	i = 0;
	while (user_inputs[i])
	{
		data->user_input = ft_strdup(user_inputs[i]);
		if (parse_user_input(data) == true)
			g_last_exit_code = execute(data);
		else
			g_last_exit_code = 1;
		i++;
		free_data(data, false);
	}
	free_str_tab(user_inputs);
}

/* Starts minishell by checking arguments and running either interactive
 * or non-interactive mode. Exit with last command or exit status. */
int main(int ac, char **av, char **env)
{
	t_data data;

	ft_memset(&data, 0, sizeof(t_data));
	if (!args_check(&data, ac, av) || !init_data(&data, env))
		exit_shell(NULL, EXIT_FAILURE);
	if (data.interactive)
		minishell_interactive(&data);
	else
		minishell_noninteractive(&data, av[2]);
	exit_shell(&data, g_last_exit_code);
	return (0);
}

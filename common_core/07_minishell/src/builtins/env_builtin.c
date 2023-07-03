/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:09:42 by Manny             #+#    #+#             */
/*   Updated: 2023/06/28 12:58:00 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Prints the environment variables to stdout.
 * Returns 0 on success or 1 if no environment variables are found. */
int	env_builtin(t_data *data, char **args)
{
	int	i;

	if (args && args[1])
		return (errmsg_cmd("env", NULL, "too many arguments", 2));
	i = 0;
	if (!data->env)
		return (EXIT_FAILURE);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], "OLDPWD=", 7) != 0
			|| data->env[i][7] != '\0')
			ft_putendl_fd(data->env[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}

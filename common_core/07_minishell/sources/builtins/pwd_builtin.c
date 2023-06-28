/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:21:29 by Manny             #+#    #+#             */
/*   Updated: 2023/06/24 19:45:18 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Prints the current working directory path.
 * Returns 0 on success or 1 on failure. */
int	pwd_builtin(t_data *data, char **args)
{
	char	buf[PATH_MAX];
	char	*cwd;

	(void)args;
	if (data->wd)
	{
		ft_putendl_fd(data->wd, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	cwd = getcwd(buf, PATH_MAX);
	if (cwd)
	{
		ft_putendl_fd(cwd, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	errmsg_cmd("pwd", NULL, strerror(errno), errno);
	return (EXIT_FAILURE);
}

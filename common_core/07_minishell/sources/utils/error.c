/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:12:54 by Manny             #+#    #+#             */
/*   Updated: 2023/06/22 14:54:23 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Joins 2 strings, frees the first one and returns the new string.
 * or NULL if mem alloc error */
char	*join_strs(char *str, char *add)
{
	char	*tmp;

	if (!add)
		return (str);
	if (!str)
		return (ft_strdup(add));
	tmp = str;
	str = ft_strjoin(str, add);
	free_ptr(tmp);
	return (str);
}

/* Checks the quotes around the error detail.
 * Returns true if the command is export or unset, false if not. */
static bool	add_detail_quotes(char *cmd)
{
	if (ft_strncmp(cmd, "export", 7) == 0 || ft_strncmp(cmd, "unset", 6) == 0)
		return (true);
	return (false);
}

/* Prints an error message to the standard error, prefixed with the
 * program name. Returns with the specified error number. */

int	errmsg_cmd(char *cmd, char *detail, char *error_msg, int error_nb)
{
	char	*msg;
	bool	detail_quotes;

	detail_quotes = add_detail_quotes(cmd);
	msg = ft_strdup("minishell: ");
	if (cmd != NULL)
	{
		msg = join_strs(msg, cmd);
		msg = join_strs(msg, ": ");
	}
	if (detail != NULL)
	{
		if (detail_quotes)
			msg = join_strs(msg, "`");
		msg = join_strs(msg, detail);
		if (detail_quotes)
			msg = join_strs(msg, "'");
		msg = join_strs(msg, ": ");
	}
	msg = join_strs(msg, error_msg);
	ft_putendl_fd(msg, STDERR_FILENO);
	free_ptr(msg);
	return (error_nb);
}

/* Prints an error message not related to a command. Used for syntax errors. */
void	errmsg(char *errmsg, char *detail, int quotes)
{
	char	*msg;

	msg = ft_strdup("minishell: ");
	msg = join_strs(msg, errmsg);
	if (quotes)
		msg = join_strs(msg, " `");
	else
		msg = join_strs(msg, ": ");
	msg = join_strs(msg, detail);
	if (quotes)
		msg = join_strs(msg, "'");
	ft_putendl_fd(msg, STDERR_FILENO);
	free_ptr(msg);
}

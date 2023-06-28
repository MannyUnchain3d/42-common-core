/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:30:03 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/25 18:46:13 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exp_other_here(char *token, char **new);

/* Frees the temporary heredoc files created during command execution.*/
void	heredoc_free(t_data *data)
{
	int		i;
	t_cmd	*cmd;
	char	*name;
	char	*tmp;

	i = 0;
	cmd = data->cmd;
	while (cmd)
	{
		tmp = ft_itoa(i++);
		name = ft_strjoin(HEREDOC_NAME, tmp);
		free (tmp);
		unlink(name);
		free(name);
		cmd = cmd->next;
	}
}

/* Expands "$" variables in the heredoc buffer,
 * and updates the buffer with the expanded values. */
void	here_env(char **buffer, t_data *data)
{
	char	*tmp;
	int		wlen;

	tmp = ft_strdup(*buffer);
	wlen = 0;
	buffer[0][0] = '\0';
	while (tmp[wlen] != '\0')
	{
		if (tmp[wlen] != '$')
			wlen += exp_other_here(&tmp[wlen], buffer);
		else if (tmp[wlen] == '$')
			wlen += exp_env(&tmp[wlen], data, buffer);
	}
	free (tmp);
}

/* Handles expansion of non-variable tokens in the heredoc,
 * concatenates them with the existing buffer.
 * Loops through the token until it reaches a "$" or "\0".
 * Returns the length of the processed token. */
static int	exp_other_here(char *token, char **new)
{
	int		wlen;
	char	*str;
	char	*tmp;

	wlen = 0;
	while (!ft_strchr("$\0", token[wlen]))
		wlen++;
	str = ft_calloc (wlen + 1, sizeof(char));
	ft_strlcpy (str, token, wlen + 1);
	tmp = ft_strjoin(*new, str);
	free (str);
	if (*new)
		free (*new);
	*new = tmp;
	return (wlen);
}

/* Handles error messages for heredoc redirections.
 * Cleans up the allocated memory.
 * Returns -1 if an error occurs, 0 otherwise. */
int	here_error(char *name, char *delimit, int option)
{
	if (option == 1)
	{
		errmsg("open heredoc error", strerror(errno), 0);
		free(name);
		free(delimit);
		return (-1);
	}
	else if (option == 2)
	{
		errmsg("warning", "here-document delimited by end-of-file", 0);
		free(name);
		free(delimit);
		return (-1);
	}
	return (0);
}

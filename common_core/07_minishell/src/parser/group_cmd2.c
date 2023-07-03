/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_cmd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:32:03 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/29 00:31:07 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cmd_table2(t_list *tokens, char *content, char **result, int cnt);
static int	cmd_table3(char *content, char **result, int cnt);

/* Extracts command arguments from the token list and stores them in an array.
 * Handles cases based on the presence of a specific sign or redirection.
 * Returns the updated count of arguments. */
char	**cmd_table(t_list *tokens, const char *sig, int count)
{
	char	*content;
	char	**result;
	int		cnt;

	cnt = 0;
	result = ft_calloc(count + 1, sizeof(*result));
	while (count > 0)
	{
		content = tokens->content;
		if (sig && !ft_strcmp(content, sig) && count--)
		{
			tokens = tokens->next;
			cnt = cmd_table2(tokens, content, result, cnt);
		}
		else if (is_redirect(content) && count--)
			tokens = tokens->next;
		else if (!sig && !is_redirect(content) && !is_opt(content))
			cnt = cmd_table3(content, result, cnt);
		count--;
		tokens = tokens->next;
	}
	result[cnt] = NULL;
	return (result);
}

/* Handles the case of a sign being present in the token list. */
static int	cmd_table2(t_list *tokens, char *content, char **result, int cnt)

{
	char	*tmp;

	content = tokens->content;
	tmp = erase_q(content);
	if (tmp && ft_strlen(tmp))
		result[cnt++] = tmp;
	else
		free (tmp);
	return (cnt);
}

/* Handles the case of no redirection, and no operator being present
 * in the token list. */
static int	cmd_table3(char *content, char **result, int cnt)
{
	char	*tmp;

	tmp = erase_q(content);
	if (tmp && ft_strlen(tmp))
		result[cnt++] = tmp;
	else
		free (tmp);
	return (cnt);
}

/* Checks for conflicting redirections in the command, if it has
 * more than one heredoc_delimiter, or both outfile and append,
 * or both infile and heredoc_delimiter.
 * Returns 1 if there is a conflict, 0 otherwise. */
int	check_redirect(t_cmd *tmp)
{
	if (tmp->io_fds->heredoc_delimiter[0] && tmp->io_fds->heredoc_delimiter[1])
		return (1);
	else if (tmp->io_fds->outfile[0] && tmp->io_fds->append[0])
		return (1);
	else if (tmp->io_fds->infile[0] && tmp->io_fds->heredoc_delimiter[0])
		return (1);
	else
		return (0);
}

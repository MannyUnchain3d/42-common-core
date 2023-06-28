/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:46:24 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/25 23:54:15 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Appends a single quote to the given string. */
static void	append_dquote(char **new)
{
	char	*tmp;

	tmp = ft_strjoin (*new, "\"");
	if (*new)
		free (*new);
	*new = tmp;
}

/* Parses a token enclosed in double quotes by expanding
 * env vars or by handling other cases.
 * Returns the length of the token. */
int	parse_dquote(char *token, t_data *data, char **new)
{
	int		wlen;
	int		pos;
	char	*tmp;

	wlen = 1;
	if (*token != '"')
		return (0);
	append_dquote(new);
	while (token[wlen] && token[wlen] != '"')
	{
		if (token[wlen] == '$')
			pos = exp_env(&token[wlen], data, new);
		else
			pos = exp_d_quote(&token[wlen], new);
		wlen += pos;
	}
	if (token[wlen] == '"')
	{
		tmp = ft_strjoin (*new, "\"");
		if (*new)
			free (*new);
		*new = tmp;
		wlen++;
	}
	return (wlen);
}

/* Parses a token by expanding single quotes, double quotes,
 * env vars or by handling other cases.
 * Returns the parsed token. */
static char	*parse_real(char *content, t_data *data)
{
	char	*new;
	int		wlen;

	new = ft_calloc (1, sizeof(char));
	while (*content != '\0')
	{
		if (*content == '\'')
			wlen = exp_s_quote(content, &new);
		else if (*content == '\"')
			wlen = parse_dquote(content, data, &new);
		else
			wlen = parse_other(content, data, &new);
		content += wlen;
	}
	return (new);
}

/* Parses the tokens list by expanding quotes,
 * env vars or by handling other cases. */
void	parsing(t_list **tokens, t_data *data)
{
	t_list	*tmp;
	char	*new;
	char	*keep;

	tmp = *tokens;
	while (tmp)
	{
		keep = tmp->content;
		new = parse_real(tmp->content, data);
		tmp->content = new;
		free (keep);
		tmp = tmp->next;
	}
	return ;
}

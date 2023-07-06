/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_cmd3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:24:41 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/25 23:02:47 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exp_other_fin(char *token, char **new);
static int	exp_s_quote_fin(char *token, char **new);
static int	parse_dquote_fin(char *token, char **new);
static int	parse_other_fin(char *content, char **new);

/* Remove quotes from the given string and return the new string. */
char	*erase_q(char *content)
{
	char	*new;
	int		wlen;

	new = ft_calloc (1, sizeof(char));
	while (*content != '\0')
	{
		if (*content == '\'')
			wlen = exp_s_quote_fin(content, &new);
		else if (*content == '\"')
			wlen = parse_dquote_fin(content, &new);
		else
			wlen = parse_other_fin(content, &new);
		content += wlen;
	}
	return (new);
}

/* Parses the substring until it finds a quote or the end of the string.
 * Returns the length of the parsed string. */
static int	parse_other_fin(char *content, char **new)
{
	int	slen;

	slen = 0;
	while (content[slen] && !ft_strchr("\"'", content[slen]))
		slen += exp_other_fin((content + slen), new);
	return (slen);
}

/* Finds the length of the substring until it finds a quote or the end of the
 * string. Appends the substring to the new string.
 * Returns the length of the parsed string. */
static int	exp_other_fin(char *token, char **new)
{
	int		wlen;
	char	*str;
	char	*tmp;

	wlen = 0;
	while (!ft_strchr("\"'\0", token[wlen]))
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

/* Parses the substring enclosed within double quotes.
 * Appends the substring to the new string.
 * Returns the length of the parsed string. */
static int	parse_dquote_fin(char *token, char **new)
{
	int		wlen;
	char	*str;
	char	*tmp;

	if (*token != '\"')
		return (0);
	wlen = 1;
	while (token[wlen] != '\"')
		wlen++;
	str = ft_calloc (wlen, sizeof(char));
	ft_strlcpy(str, token + 1, wlen);
	tmp = ft_strjoin (*new, str);
	free (str);
	if (*new)
		free (*new);
	*new = tmp;
	return (wlen + 1);
}

/* Finds the length of the substring enclosed within single quotes.
 * Appends the substring to the new string.
 * Returns the length of the parsed string. */
static int	exp_s_quote_fin(char *token, char **new)
{
	int		wlen;
	char	*str;
	char	*tmp;

	if (*token != '\'')
		return (0);
	wlen = 1;
	while (token[wlen] != '\'')
		wlen++;
	str = ft_calloc (wlen, sizeof(char));
	ft_strlcpy(str, token + 1, wlen);
	tmp = ft_strjoin (*new, str);
	free (str);
	if (*new)
		free (*new);
	*new = tmp;
	return (wlen + 1);
}

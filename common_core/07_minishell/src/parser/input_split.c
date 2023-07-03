/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:09:05 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/25 23:18:43 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Splits the given line into tokens, and returns a list of tokens.
 * Returns NULL if the line is invalid. */
t_list	*input_split(char *line)
{
	int		wlen;
	t_list	*token;

	token = NULL;
	while (*line)
	{
		wlen = add_token(&token, line);
		if (wlen < 0)
		{
			ft_lstclear(&token, &free_token);
			return (NULL);
		}
		line += wlen;
		if (!ft_strchr(DEMARK, *line))
			continue ;
		while (*line && ft_strchr(DEMARK, *(++line)))
			if (!*line)
				break ;
	}
	return (token);
}

/* Adds a token to the 'token' list. Returns the length of the token.
 * Returns -1 if the token is invalid. */
int	add_token(t_list **token, char *line)
{
	int		wlen;
	char	*word;
	t_list	*new;

	wlen = wordlen(line);
	if (wlen < 0)
		return (-1);
	word = ft_calloc(sizeof(char), wlen + 1);
	ft_strlcpy(word, line, wlen + 1);
	new = ft_lstnew(word);
	if (!token)
		*token = new;
	else
		ft_lstadd_back(token, new);
	return (wlen);
}

void	free_token(void *content)
{
	free(content);
}

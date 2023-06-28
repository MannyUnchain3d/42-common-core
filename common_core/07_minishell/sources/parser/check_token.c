/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:06:51 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/29 00:29:56 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Checks if quotes in a string are properly closed. */
static int	valid_quote(char *str)
{
	char	check;

	check = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"' )
		{
			check = *str++;
			while (*str)
			{
				if (*str == check)
				{
					check = 0;
					break ;
				}
				str++;
			}
		}
		if (*str == '\0')
			break ;
		str++;
	}
	return (check == 0);
}

/* Prechecks if the first token is a symbol to avoid a syntax error. */
int	precheck_token(t_list **tokens)
{
	t_list	*tmp;
	char	*str;

	tmp = *tokens;
	str = tmp->content;
	if (!ft_strncmp(str, "|", 2) | !ft_strncmp(str, "&&", 3)
		|| !ft_strncmp(str, "&", 2) || !ft_strncmp(str, ";;", 3)
		|| !ft_strncmp(str, ";", 2))
	{
		errmsg("syntax error near unexpected token", str, 1);
		return (0);
	}
	return (1);
}

/* Checks if the token are valid by considering its helpers functions.
 * Prints an error message if a token is invalid.
 * Returns 1 if the tokens are valid, 0 otherwise. */
int	check_token(t_list **tokens)
{
	t_list	*tmp;
	char	*str;
	char	*n_str;

	tmp = *tokens;
	n_str = NULL;
	while (tmp)
	{
		str = tmp->content;
		if (tmp->next)
			n_str = tmp->next->content;
		if (!valid_quote(str) || \
			((is_redirect(str) || is_opt(str)) && !tmp->next) \
			|| (is_opt(str) && is_opt(n_str)) || \
			(is_redirect(str) && (is_opt(n_str) || is_redirect(n_str))))
		{
			if (n_str)
				errmsg("syntax error near unexpected token", n_str, 1);
			else
				errmsg("syntax error near unexpected token", str, 1);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

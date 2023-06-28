/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <nicklaw@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:08:28 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/27 09:50:19 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	qlen(char *str);

/* Calculates the length of a word within a string,
 * considering special characters and quotes.
 * Returns the length of the word */
int	wordlen(char *str)
{
	int	i;

	i = 0;
	if (is_redirect(str))
		return (is_redirect(str));
	else if (is_opt(str))
		return (is_opt(str));
	while (str[i] && !ft_strchr(" \n\t<>|", str[i]))
	{
		if (ft_strchr(QUOTES, str[i]))
			i += qlen(&str[i]);
		else
			i++;
	}
	return (i);
}

/* Calculates the length of a quoted section within a string.
 * Returns the length of the quoted section */
static int	qlen(char *str)
{
	int	i;

	if (!ft_strchr(QUOTES, *str))
		return (0);
	i = 1;
	while (str[i] && str[i] != str[0])
		i++;
	if (str[i] == str[0])
		return (++i);
	return (i);
}

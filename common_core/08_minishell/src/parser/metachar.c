/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metachar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:07:00 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/27 11:57:46 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Checks if the given string represents an operator symbol '|'.
 * Returns 0 on empty string, or if it is '|'.
 * Returns 1 if the symbol is not '|', and -1 otherwise. */
int	is_opt(char *str)
{
	if (!str)
		return (0);
	if (*str != '|')
		return (0);
	else if (!ft_strncmp("|", str, 1))
		return (1);
	else
		return (-1);
}

/* Checks if the given string represents a redirection symbol ('>' or '<').
 * Returns 1 if the string is '>' or '<', 2 if the string is '>>' or '<<',
 * and 0 otherwise. */
int	is_redirect(char *str)
{
	if (!str)
		return (0);
	if (*str != '>' && *str != '<')
		return (0);
	if (!ft_strncmp(">>", str, 2))
		return (2);
	else if (!ft_strncmp("<<", str, 2))
		return (2);
	else if (!ft_strncmp(">", str, 1) || !ft_strncmp("<", str, 1))
		return (1);
	else
		return (-1);
}

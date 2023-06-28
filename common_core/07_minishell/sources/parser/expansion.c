/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:46:47 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/25 21:48:00 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Expands the content between quotes (excluding double quote, '$', and '\0')
 * in the 'token' string, and appends the expanded content to the 'new' string.
 * Returns the length of the content between quotes. */
int	exp_other(char *token, char **new)
{
	int		wlen;
	char	*str;
	char	*tmp;

	wlen = 0;
	while (!ft_strchr("\"$'\0", token[wlen]))
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

/* Expands the content between single quotes in the 'token' string,
 * and appends the expanded content to the 'new' string.
 * The content between single quotes remains unchanged.
 * Returns the length of the content between single quotes. */
int	exp_s_quote(char *token, char **new)
{
	int		wlen;
	char	*str;
	char	*tmp;

	if (*token != '\'')
		return (0);
	wlen = 1;
	while (token[wlen] != '\'')
		wlen++;
	str = ft_calloc (wlen + 2, sizeof(char));
	ft_strlcpy(str, token, wlen + 2);
	tmp = ft_strjoin (*new, str);
	free (str);
	if (*new)
		free (*new);
	*new = tmp;
	return (wlen + 1);
}

/* Expands the content between double quotes (excluding double quote and '$'),
 * in the 'token' string and appends the expanded content to the 'new' string.
 * Returns the length of the content between double quotes. */
int	exp_d_quote(char *token, char **new)
{
	int		wlen;
	char	*str;
	char	*tmp;

	wlen = 0;
	while (!ft_strchr("\"$", token[wlen]))
		wlen++;
	str = ft_calloc (wlen + 1, sizeof(char));
	ft_strlcpy(str, token, wlen + 1);
	tmp = ft_strjoin (*new, str);
	free (str);
	if (*new)
		free (*new);
	*new = tmp;
	return (wlen);
}

/* Finds the last occurrence of the substring 'str2' within 'str'.
 * Returns a pointer to the last occurrence of 'str2' or NULL if not found. */
char	*ft_strrstr(const char *str, const char *str2)
{
	int			offset1;
	int			offset2;

	offset1 = ft_strlen(str) - 1;
	offset2 = ft_strlen(str2) - 1;
	if (offset2 > offset1)
		return (0);
	while (offset1 >= 0)
	{
		offset2 = ft_strlen(str2) - 1;
		while (offset2 >= 0 && str[offset1] == str2[offset2])
		{
			offset1--;
			offset2--;
			if (offset2 == -1)
				return ((char *)&str[offset1 + 1]);
		}
		offset1--;
	}
	return (0);
}

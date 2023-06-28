/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:09:16 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/25 23:28:04 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Parses the user input by handling and processing it.
 * Returns 0 if the input is empty or contains only spaces.
 * Returns 88 if the input is invalid.
 * Returns 77 if the group command is invalid.
 * Returns 1 otherwise. */
int	parse_user_input(t_data *data)
{
	t_list	*tokens;
	int		ret;

	ret = 1;
	data->user_input = handling_input (data->user_input);
	if (data->user_input == NULL)
		return (0);
	tokens = input_split(data->user_input);
	if (!precheck_token(&tokens) || !check_token(&tokens))
	{
		ft_lstclear(&tokens, &free_token);
		return (ret = 88);
	}
	parsing(&tokens, data);
	data->cmd = group_cmd(tokens);
	if (!data->cmd)
	{
		errmsg("group command error", strerror(1), 0);
		ft_lstclear(&tokens, &free_token);
		return (ret = 77);
	}
	ft_lstclear(&tokens, &free_token);
	return (ret);
}

/* Removes leading and trailing spaces from the given input, and trims it.
 * Returns NULL if the input is empty or contains only spaces. */
char	*handling_input(char *input)
{
	char	*line;
	int		index;

	index = 0;
	while ((input[index] >= 9 && input[index] <= 13) || input[index] == ' ')
		index++;
	if (input[index] == '\0')
	{
		free(input);
		return (NULL);
	}
	line = ft_strtrim(input, "\t ");
	free(input);
	if (ft_strlen(line) == 0)
		return (NULL);
	return (line);
}

/* Parses the token by expanding environment variables or handling other cases.
 * Returns the length of the token. */
int	parse_other(char *token, t_data *data, char **new)
{
	int	wlen;

	wlen = 0;
	while (token[wlen] && !ft_strchr("\"'", token[wlen]))
	{
		if (token[wlen] == '$')
			wlen += exp_env((token + wlen), data, new);
		else
			wlen += exp_other((token + wlen), new);
	}
	return (wlen);
}

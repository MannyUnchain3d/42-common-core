/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:35:41 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/25 23:49:37 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_bonus.h"

static t_list	*parse_wildcard(t_list **tokens);

static void	append_dquote(char **new)
{
	char	*tmp;

	tmp = ft_strjoin (*new, "\"");
	if (*new)
		free (*new);
	*new = tmp;
}

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
		if (is_wild_card(keep))
			tmp = parse_wildcard(&tmp);
		free (keep);
		tmp = tmp->next;
	}
	return ;
}

static t_list	*parse_wildcard(t_list **tokens)
{
	t_list	*wild_p;
	t_list	*next;
	char	*tmp;

	tmp = (*tokens)->content;
	wild_p = wild_find(*tokens);
	if (wild_p)
	{
		next = (*tokens)->next;
		(*tokens)->content = ft_strdup(wild_p->content);
		(*tokens)->next = wild_p->next;
		ft_lstadd_back(tokens, next);
		ft_lstdelone(wild_p, &free_token);
		free(tmp);
	}
	return (*tokens);
}

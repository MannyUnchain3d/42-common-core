/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildling_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:18:38 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/25 18:59:31 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_bonus.h"

static int	is_match_path(char *srch, char *pattern);
static void	*get_paths(char *dirname, char *srch, t_list **paths);
static int	match_path2(char **name, char **srch);

int	is_wild_card(char *str)
{
	char	c;

	while (*str)
	{
		c = *str;
		if (c == '*')
			return (1);
		if ((c == '\'' || c == '"') && str++)
		{
			while (*str && *str != c)
				str++;
		}
		str++;
	}
	return (0);
}

t_list	*wild_find(t_list *tokens)
{
	t_list	*paths;
	char	*srch;

	paths = NULL;
	srch = tokens->content;
	if (*srch == '.' && *(srch + 1) == '/')
		srch += 2;
	get_paths(".", srch, &paths);
	return (paths);
}

static void	*get_paths(char *dirname, char *srch, t_list **paths)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*name;
	int				is_match;

	dir = opendir(dirname);
	if (!dir)
		return (NULL);
	entry = readdir(dir);
	while (entry)
	{
		name = entry->d_name;
		is_match = is_match_path(name, srch);
		if (is_match == 0 && *name != '.')
			ft_lstadd_back(paths, ft_lstnew(ft_strdup(name)));
		entry = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}

static int	is_match_path(char *name, char *srch)
{
	int	ret;

	while (*srch)
	{
		if (*srch == '*')
		{
			ret = match_path2(&name, &srch);
			if (ret == 0)
				return (0);
			else if (ret == -1)
				return (-1);
		}
		if (*srch != *name)
			return (-1);
		name++;
		srch++;
		if (!*srch && !*name)
			return (0);
	}
	return (-99);
}

static int	match_path2(char **name, char **srch)
{
	while (**srch == '*')
		(*srch)++;
	if (!ft_strchr(*srch, '*'))
	{
		if (!**srch || (ft_strrstr(*name, *srch) && \
			ft_strlen(*srch) == ft_strlen(ft_strrstr(*name, *srch))))
			return (0);
		else
			return (-1);
	}
	else
	{
		while (**name && **srch != **name)
			(*name)++;
	}
	return (99);
}

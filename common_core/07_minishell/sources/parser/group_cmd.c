/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:39:41 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/25 22:37:02 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	config_cmd(t_list *tokens, t_cmd *tmp);
static void	connect_cmd(t_cmd **res, t_cmd *tmp);
static int	t_cnt_cmd(t_list *tokens, t_cmd *tmp);

/* Groups tokens into command structures. Each cmd struct contains
 * a single or a series of piped commands. */
t_cmd	*group_cmd(t_list *tokens)
{
	t_cmd	*res;
	t_cmd	*tmp;
	int		cmd_count;

	res = 0;
	while (tokens)
	{
		tmp = ft_calloc (1, sizeof(*tmp));
		if (!tmp)
			return (NULL);
		tmp->pipe_fd[0] = -1;
		tmp->pipe_fd[1] = -1;
		cmd_count = config_cmd(tokens, tmp);
		if (!cmd_count)
		{
			clear_cmd(res);
			res = NULL;
			return (res);
		}
		while (tokens && cmd_count-- > 0)
			tokens = tokens->next;
		connect_cmd(&res, tmp);
	}
	return (res);
}

/* Connects the command structures to each other. */
static void	connect_cmd(t_cmd **res, t_cmd *tmp)
{
	t_cmd	*std;

	std = *res;
	if (!std)
		*res = tmp;
	else
	{
		while (std->next)
			std = std->next;
		tmp->prev = std;
		std->next = tmp;
	}
	return ;
}

/* Initializes the I/O fds struct with default values. */
static void	set_io(t_io_fds *io)
{
	io->infile = NULL;
	io->outfile = NULL;
	io->append = NULL;
	io->heredoc_delimiter = NULL;
	io->heredoc_quotes = false;
	io->fd_in = -1;
	io->fd_out = -1;
	io->fd_append = -1;
	io->stdin_backup = -1;
	io->stdout_backup = -1;
}

/* Configures a command structure by extracting and assigning the tokens
 * to the appropriate fields.
 * Returns the number of tokens that were used to configure the command. */
static int	config_cmd(t_list *tokens, t_cmd *tmp)
{
	int	j;

	tmp->io_fds = ft_calloc(1, sizeof(t_io_fds));
	set_io(tmp->io_fds);
	j = t_cnt_cmd(tokens, tmp);
	tmp->io_fds->outfile = cmd_table(tokens, ">", j);
	tmp->io_fds->append = cmd_table(tokens, ">>", j);
	tmp->io_fds->infile = cmd_table(tokens, "<", j);
	tmp->io_fds->heredoc_delimiter = cmd_table(tokens, "<<", j);
	tmp->args = cmd_table(tokens, NULL, j);
	tmp->cmd = tmp->args[0];
	if (check_redirect(tmp))
		return (0);
	return (j);
}

/* Counts and returns the number of tokens in the current command. */
static int	t_cnt_cmd(t_list *tokens, t_cmd *tmp)
{
	t_list	*lst;
	int		j;

	j = 0;
	lst = tokens;
	while (lst)
	{
		j++;
		if (is_opt((char *)lst->content) > 0)
		{
			tmp->pipe_output = true;
			return (j);
		}
		lst = lst->next;
	}
	tmp->pipe_output = false;
	return (j);
}

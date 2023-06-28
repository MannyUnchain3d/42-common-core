/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_cmd4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:49:51 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/25 23:13:18 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clear_cmd2(t_cmd *cmd);

/* Frees memory allocated for all the command structures in the linked list. */
void	clear_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	if (!cmd)
		return ;
	while (cmd)
	{
		tmp = cmd->next;
		clear_cmd2(cmd);
		i = 0;
		while (cmd->io_fds->heredoc_delimiter[i])
			free(cmd->io_fds->heredoc_delimiter[i++]);
		free(cmd->io_fds->heredoc_delimiter);
		i = 0;
		if (cmd->io_fds)
			free(cmd->io_fds);
		free (cmd);
		cmd = 0;
		cmd = tmp;
	}
}

/* Helper function to free memory allocated for a single command structure. */
static void	clear_cmd2(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
	{
		free(cmd->args[i]);
		cmd->args[i++] = 0;
	}
	free(cmd->args);
	i = 0;
	while (cmd->io_fds->infile[i])
		free(cmd->io_fds->infile[i++]);
	free(cmd->io_fds->infile);
	i = 0;
	while (cmd->io_fds->outfile[i])
		free(cmd->io_fds->outfile[i++]);
	free(cmd->io_fds->outfile);
	i = 0;
	while (cmd->io_fds->append[i])
		free(cmd->io_fds->append[i++]);
	free(cmd->io_fds->append);
}

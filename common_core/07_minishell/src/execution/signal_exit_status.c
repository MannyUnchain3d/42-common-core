/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_exit_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:42:57 by Manny             #+#    #+#             */
/*   Updated: 2023/06/27 19:43:55 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_exit_status(int save_stat)
{
	int	status;

	if (WIFSIGNALED(save_stat))
	{
		if (WTERMSIG(save_stat) == SIGQUIT || WEXITSTATUS(save_stat) == 131)
			printf("Quit: 3\n");
		else if (WTERMSIG(save_stat) == SIGINT || WEXITSTATUS(save_stat) == 130)
			printf("\n");
		status = 128 + WTERMSIG(save_stat);
	}
	else if (WIFEXITED(save_stat))
	{
		if (WTERMSIG(save_stat) == SIGQUIT || WEXITSTATUS(save_stat) == 131)
			printf("Quit: 3\n");
		else if (WTERMSIG(save_stat) == SIGINT || WEXITSTATUS(save_stat) == 130)
			printf("\n");
		status = WEXITSTATUS(save_stat);
	}
	else
		status = save_stat;
	return (status);
}

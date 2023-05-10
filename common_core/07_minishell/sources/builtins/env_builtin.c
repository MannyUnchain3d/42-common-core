/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:09:42 by Manny             #+#    #+#             */
/*   Updated: 2023/05/10 18:09:42 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Executes the builtin env command: Prints the environment variables. */

int env_builtin(t_data *data, char **args)
{
    int i;

    if (args && args[1])
        return (errmsg_cmd("env", NULL, "too many arguments", 2));
}
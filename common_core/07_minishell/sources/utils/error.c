/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:12:54 by Manny             #+#    #+#             */
/*   Updated: 2023/05/10 18:53:03 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Joins 2 strings, frees the first one and returns the new string.
 * or NULL if mem alloc error */
char    *join_strs(char *str, char *add)
{
    char *tmp;

    if (!add)
        return (str);
    if (!str)
        return (ft_strdup(add));
    tmp = str;
    str = ft_strjoin(str, add);
    free_ptr(tmp);
    return (str);
}

/* Checks the quotes around 
 * Returns true if the command is export or unset, false if not
static bool add_detail_quotes(char *cmd)
{
    if (ft_strncmp(cmd, "export", 7) == 0 || ft_strncmp(cmd, "unset", 6) == 0)
        return (true);
    return (false);
}
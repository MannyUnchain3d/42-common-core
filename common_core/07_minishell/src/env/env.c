/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:20:23 by Manny             #+#    #+#             */
/*   Updated: 2023/05/01 16:57:25 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int env_var_count(char **env)
{
    int i;

    i = 0;
    while (env && env[i])
        i++;
    return (i);
}

int get_env_var_index(char **env, char *var)
{
    int     i;
    char    *tmp;

    tmp = ft_strjoin(var, "=");
    if (!tmp)
        return (-1);
    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], tmp, ft_strlen(tmp)) == 0)
        {
            free_ptr(tmp);
            return (i);
        }
        i++;
    } 
    free_ptr(tmp);
    return (-1);
}


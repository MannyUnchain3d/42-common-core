/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:13:44 by Manny             #+#    #+#             */
/*   Updated: 2023/05/01 21:33:46 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void update_wd(t_data *data, char *wd)
{
    set_env_var(data, "OLDPWD", get_env_var_value(data->env, "PWD"));
    set_env_var(data, "PWD", wd);
    if (data->old_wd)
    {
        free_ptr(data->old_wd);
        data->old_wd = ft_strdup(data->wd);
    }
    if (data->wd)
    {
        free_ptr(data->wd);
        data->wd = ft_strdup(wd);
    }
    free_ptr(wd);
}

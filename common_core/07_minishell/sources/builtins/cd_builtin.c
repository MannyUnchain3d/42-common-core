/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:13:44 by Manny             #+#    #+#             */
/*   Updated: 2023/05/03 17:29:00 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Updates the PWD and OLDPWD after a change of directory. 
 * Copies of the paths are made in case `unset` is use. */
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

/* Sets errno to ENOENT ("no such file or directory")
 * if chdir sets it to ESTALE ("Stale file handle").
 * It can happen on some systems when a parent directory is removed,
 * because the inode table entry is recycled. */ 
static bool chdir_errno_mod(char *path)
{
    if (errno == ESTALE)
        errno = ENOENT;
    errmsg_cmd("cd", path, strerror(errno), errno);
    return (false);
}

/* Changes the current working directory and updates the
 * OLDPWD environment variable.
 * Returns 1 on success, 0 on failure. */
static bool change_dir(t_data *data, char *path)
{
    char    *ret;
    char    *tmp;
    char    cwd[PATH_MAX];

    ret = NULL;
    if (chdir(path) != 0)
        return (chdir_errno_mod(path));
    ret = getcwd(cwd, PATH_MAX);
    if (!ret)
    {
        errmsg_cmd("cd: error retrieving current directory",
            "getcwd: cannot access parent directories",
            strerror(errno), errno);
        ret = ft_strjoin(data->wd, " /");
        tmp = ret;
        ret = ft_strjoin(tmp, path);
        free_ptr(tmp);
    }
    else
        ret = ft_strdup(cwd);
    update_wd(data, ret);
    return (true);
}

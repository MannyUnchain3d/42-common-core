/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:21:25 by Manny             #+#    #+#             */
/*   Updated: 2023/06/24 19:41:12 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Prints the environment variables marked for export in the format:
 * declare -x <key>="<value>". If the environment var is OLDPWD and it has no
 * value, it is printed without equal sign and double quotes. */
static int	export_env(t_data *data)
{
	int		i;
	char	*env_var;
	char	*eq_sign;

	i = 0;
	if (!data->env)
		return (EXIT_FAILURE);
	while (data->env[i])
	{
		printf("declare -x ");
		env_var = ft_strdup(data->env[i]);
		eq_sign = ft_strchr(env_var, '=');
		if (eq_sign)
		{
			*eq_sign = '\0';
			if (ft_strcmp(env_var, "OLDPWD") == 0 && *(eq_sign + 1) == '\0')
				printf("%s\n", env_var);
			else
				printf("%s=\"%s\"\n", env_var, eq_sign + 1);
		}
		free(env_var);
		i++;
	}
	return (EXIT_SUCCESS);
}

/* Separates the argument into a key-value pair for the environment variable.
 * Returns an array of strings containing the key and value or NULL if error */
static char	**get_key_value_pair(char *arg)
{
	char	**tmp;
	char	*eq_sign;

	eq_sign = ft_strchr(arg, '=');
	tmp = malloc(sizeof * tmp * (2 + 1));
	tmp[0] = ft_substr(arg, 0, eq_sign - arg);
	tmp[1] = ft_substr(eq_sign, 1, ft_strlen(eq_sign));
	tmp[2] = NULL;
	return (tmp);
}

/* Adds the given variables to the environment. If no arguments are given,
 * prints all the environment variables marked for export.
 * Returns 0 on success, 1 on failure. */
int	export_builtin(t_data *data, char **args)
{
	char	**tmp;
	int		i;
	int		ret;

	ret = EXIT_SUCCESS;
	i = 1;
	if (!args[i])
		return (export_env(data));
	while (args[i])
	{
		if (!is_valid_env_var_key(args[i]))
		{
			errmsg_cmd("export", args[i], "not a valid identifier", false);
			ret = EXIT_FAILURE;
		}
		else if (ft_strchr(args[i], '=') != NULL)
		{
			tmp = get_key_value_pair(args[i]);
			set_env_var(data, tmp[0], tmp[1]);
			free_str_tab(tmp);
		}
		i++;
	}
	return (ret);
}

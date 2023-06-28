/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <nicklaw@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:35:43 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/28 13:24:29 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	var_len(char *s);
static char	*var_value(int vlen, char *token, t_data *data);

/* Joins the contents of 'var' to the end of 'new' string,
 * and updates 'new' accordingly.
 * Frees the 'var' string and previous content of 'new' if necessary. */
static void	env_join(char **new, char *var)
{
	char	*tmp;

	tmp = ft_strjoin(*new, var);
	free (var);
	if (*new)
		free (*new);
	*new = tmp;
}

/* Expands the env variable represented by 'token' and retrieves its value.
 * If the variable exists, the value is assigned to 'var'.
 * If the variable does not exist, an empty 'var' string is created.
 * Returns the length of the variable name plus */
static int	exp_env2(char *token, t_data *data, char **var)
{
	int	wlen;

	wlen = var_len(token + 1);
	if (wlen > 0)
		*var = var_value(wlen, token + 1, data);
	else
	{
		*var = ft_calloc(1, sizeof(*var));
		**var = '\0';
	}
	return (wlen);
}

/* Expands the env variables in the 'token' string and appends the expanded
 * content to the 'new' string. The expanded string is created by replacing the
 * environment variables with their corresponding values.
 * Checks for the special case of '$?' and '$' followed by a non-alphanumeric.
 * Returns the length of the expanded string plus one (for the '$' char). */
int	exp_env(char *token, t_data *data, char **new)
{
	char	*var;
	int		wlen;

	if (*token != '$')
		return (0);
	if (*(token + 1) == '?')
	{
		var = ft_itoa(data->last_exit_code);
		wlen = 1;
	}
	else if (!ft_isalnum(*(token + 1)) && *(token + 1) != '_')
	{
		var = ft_calloc (2, sizeof(var));
		*var = '$';
		wlen = 0;
	}
	else
		wlen = exp_env2(token, data, &var);
	env_join(new, var);
	return (wlen + 1);
}

/* Returns the length of the given environment variable name. */
static int	var_len(char *s)
{
	int		i;

	i = 0;
	while (ft_isalnum(s[i]) || s[i] == '_')
		i++;
	i++;
	return (i - 1);
}

/* Returns the value of the given environment variable.
 * If the variable is not found, returns an empty string. */
static char	*var_value(int vlen, char *token, t_data *data)
{
	int		ind;
	char	*var;
	char	*val;

	var = ft_calloc(vlen + 1, sizeof(char));
	ft_strlcpy(var, token, vlen + 1);
	ind = get_env_var_index(data->env, var);
	if (ind != -1)
		val = ft_substr(ft_strchr(data->env[ind], '='), \
			1, ft_strlen(ft_strchr(data->env[ind], '=')));
	else
	{
		val = ft_calloc(1, sizeof(char));
		*val = '\0';
	}
	free (var);
	return (val);
}

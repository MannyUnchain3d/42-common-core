/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:41:34 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/07 13:24:41 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_dir(char *arg)
{
	int		fd;
	bool	ret;

	ret = false;
	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		ret = true;
	}
	return (ret);
}

static bool	is_cub_file(char *arg)
{
	char	*file;

	file = ft_strchr(arg, '.');
	if (ft_strncmp(file, ".cub", 5))
		return (false);
	return (true);
}

static bool	is_xpm_file(char *arg)
{
	char	*file;

	file = NULL;
	if (arg[0] == '.')
		file = ft_strchr(&arg[1], '.');
	else
		file = ft_strchr(arg, '.');
	if (ft_strncmp(file, ".xpm", 5))
		return (false);
	return (true);
}

int	check_file(char *arg, bool cub)
{
	if (is_dir(arg))
		return (err_msg(arg, ERR_FILE_IS_DIR, FAILURE));
	if (cub && !is_cub_file(arg))
		return (err_msg(arg, ERR_FILE_NOT_CUB, FAILURE));
	if (!cub && !is_xpm_file(arg))
		return (err_msg(arg, ERR_FILE_NOT_XPM, FAILURE));
	return (SUCCESS);
}

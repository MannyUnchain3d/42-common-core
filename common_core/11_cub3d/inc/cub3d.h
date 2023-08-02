/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:38:09 by Manny             #+#    #+#             */
/*   Updated: 2023/08/01 23:07:28 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "colors.h"
# include "libft.h"
# include "mlx.h"

# include <unistd.h>// write
# include <stdio.h>// printf and perror
# include <stdlib.h>// malloc, free, exit
# include <string.h>// strerror
# include <stdbool.h>
# include <fcntl.h>// open and close
# include <math.h>// sin, cos, tan, atan2, sqrt, pow
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>

# include <X11/X.h>// KeyPressMask, KeyReleaseMask, KeyPress, KeyRelease
# include <X11/keysym.h>// keycodes for X11 (linux)

/* ------ MACROS ---------------------- */

# define WIN_TITLE "cub3D"
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define TEXEL_SIZE 64

# define FOV 60
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05


/* ------ ERROR MESSAGES -------------- */

# define ERR_USAGE "Usage: ./cub3D <path_to_map/file.cub>"
# define ERR_MAP "Invalid map"
// ...
// ...
// ...
// ...

/* ------ ENUMERATIONS ---------------- */

enum e_direction
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3
};


/* ------ STRUCTURES ------------------ */

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

}	t_img;

typedef struct s_tex
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			*floor;
	int			*ceiling;
	int			size;
	int			index;
	int			x;
	int			y;
	double		pos;
	double		step;
}	t_tex;

typedef struct s_map
{
	char	*path;
	char	**file;
	int		fd;
	int		line_count;
	int		width;
	int		height;
	int		index_end_of_map;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

#endif

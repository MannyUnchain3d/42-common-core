/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:38:09 by Manny             #+#    #+#             */
/*   Updated: 2023/08/18 20:31:39 by etetopat         ###   ########.fr       */
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

# ifdef __linux__
#  include <X11/X.h>// KeyPressMask, KeyReleaseMask, KeyPress, KeyRelease
#  include <X11/keysym.h>// keycodes for X11 (linux)
# endif

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

typedef struct s_tex_info
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		*floor;
	int		*ceiling;
	int		size;
	int		index;
	int		x;
	int		y;
	double	pos;
	double	step;
}	t_tex_info;

typedef struct s_map_info
{
	char	*path;
	char	**file;
	int		fd;
	int		line_count;
	int		width;
	int		height;
	int		index_end_of_map;
}	t_map_info;

typedef struct s_minimap
{
	t_img	img;
	char	**map;
	int		size;
	int		offset_x;
	int		offset_y;
	int		tile_size;
	int		view_dist;
}	t_minimap;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	wall_dist;
	double	wall_x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	char	dir;
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		moved;
	int		move_x;
	int		move_y;
	int		rotated; // 0 = not rotated, 1 = rotated left, 2 = rotated right
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	char		**map;
	t_map_info	map_info;
	t_player	player;
	t_ray		ray;
	t_tex_info	tex_info;
	t_img		minimap;
	int			**texels;
	int			**textures;
}	t_data;


/* ------ FUNCTIONS ------------------- */

// init/init_data.c
void	init_data(t_data *data);

#endif

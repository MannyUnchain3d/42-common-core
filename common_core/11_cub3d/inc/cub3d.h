/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:38:09 by Manny             #+#    #+#             */
/*   Updated: 2023/11/02 23:47:46 by Manny            ###   ########.fr       */
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
# include <math.h>// sin, cos, tan
# include <errno.h>
//# include <sys/stat.h>
//# include <sys/types.h>

# ifdef __linux__
#  include <X11/X.h>// KeyPressMask, KeyReleaseMask, KeyPress, KeyRelease
#  include <X11/keysym.h>// keycodes for X11 (linux only)
# endif

/* ------ MACROS ---------------------- */

# define WIN_TITLE "cub3D"
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768

# define TEX_SIZE 64

// flag to check if a file is a directory
# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# ifndef BONUS
#  define BONUS 1
# endif

# if BONUS == 1
#  define ROT_SPEED 0.01
# else
#  define ROT_SPEED 0.05
# endif

# define MOVE_SPEED 0.1
# define DIST_EDGE_MOUSE_WRAP 20

/* ------ ERROR MESSAGES -------------- */

# define ERR_USAGE "Usage: ./cub3D <path_to_map/file.cub>"
# define ERR_FILE_NOT_CUB "Not a .cub file"
# define ERR_FILE_NOT_XPM "Not a .xpm file"
# define ERR_FILE_IS_DIR "Is a directory"
# define ERR_MALLOC "Could not allocate memory"
# define ERR_MLX_IMG "Could not create mlx image"
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"
# define ERR_MAP_INVALID "Invalid map, check .cub file for errors"
# define ERR_MAP_CHAR "Invalid character in map"
# define ERR_MAP_MISSING "Map is missing"
# define ERR_MAP_BORDERS "Map is not surrounded by walls"
# define ERR_MAP_SMALL "Map is too small"
# define ERR_MAP_POS "Map is not the last element in file"
# define ERR_PLAYER_MAX "Too many players in map"
# define ERR_PLAYER_DIR "Invalid player direction (not N,S,W or E)"
# define ERR_PLAYER_POS "Invalid player position"
# define ERR_CEILING_FLOOR "Invalid ceiling and/or floor color"
# define ERR_COLOR_CEILING "Invalid ceiling color"
# define ERR_COLOR_FLOOR "Invalid floor color"
# define ERR_TEX_INVALID "Invalid texture"
# define ERR_TEX_MISSING "Missing texture"
# define ERR_TEX_COLOR "Missing color(s) for ceiling and/or floor"
# define ERR_TEX_RGB "Invalid RGB value"

/* ------ ENUMERATIONS ---------------- */

enum e_output
{
	SUCCESS = 0,
	FAILURE = 1,
	ERROR = 2,
	BREAK = 3,
	CONTINUE = 4
};

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
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_tex_info
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*ceiling;
	int				*floor;
	unsigned long	ceiling_hex;
	unsigned long	floor_hex;
	int				size;
	int				index;
	int				x;
	int				y;
	double			pos;
	double			step;
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
	t_img	*img;
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
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
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
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		moved;
	int		move_x;
	int		move_y;
	int		rotate;
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
void	init_clean_img(t_img *img);
void	init_ray(t_ray *ray);

// init/init_mlx.c
void	init_mlx(t_data *data);
void	init_img(t_data *data, t_img *img, int width, int height);
void	init_tex_img(t_data *data, t_img *img, char *path);

// init/init_textures.c
void	init_textures(t_data *data);
void	init_tex_info(t_tex_info *tex);

// parsing/check_args.c
int		check_file(char *arg, bool cub);

// parsing/check_map_borders.c
int		check_sides(t_map_info *map, char **map_tab);

// parsing/check_map.c
int		check_map(t_data *data, char **map_tab);

// parsing/check_textures.c
int		check_textures(t_data *data, t_tex_info *tex);

// parsing/create_map.c
int		create_map(t_data *data, char **map_tab, int i);

// parsing/fill_color_textures.c
int		fill_color_textures(t_data *data, t_tex_info *tex, char *line, int j);

// parsing/get_file_data.c
int		get_file_data(t_data *data, char **map);

// parsing/parse_data.c
void	parse_data(char *path, t_data *data);

// parsing/utils.c
int		is_whitespace(char c);
size_t	find_map_width(t_map_info *map, int i);

// rendering/images_utils.c
void	set_image_pixel(t_img *img, int x, int y, int color);

// rendering/raycasting.c
int		raycasting(t_player *player, t_data *data);

// rendering/render.c
int		render(t_data *data);
void	render_images(t_data *data);

// rendering/textures.c
void	init_texels(t_data *data);
void	update_texels(t_data *data, t_tex_info *tex, t_ray *ray, int x);

// movements/input_handler.c
void	listen_for_input(t_data *data);

/* movement/player_dir.c */
void	init_player_dir(t_data *data);

/* movement/player_move.c */
int		move_player(t_data *data);

/* movement/player_pos.c */
int		validate_move(t_data *data, double new_x, double new_y);

/* movement/player_rotate.c */
int		rotate_player(t_data *data, double rotdir);

// error.c
int		err_msg(char *detail, char *str, int code);
int		err_msg_nb(int nb, char *str, int code);

// exit/exit.c
void	clean_exit(t_data *data, int code);
int		quit_cub3d(t_data *data);

// exit/free_data.c
int		free_data(t_data *data);
void	free_tab(void **tab);

#endif

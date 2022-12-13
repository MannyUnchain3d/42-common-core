/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:23:47 by Manny             #+#    #+#             */
/*   Updated: 2022/12/12 15:29:45 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TRUE 1
# define FALSE 0
# define CELL_SIZE 64 // 64x64 pixels

# define KEY_ESC 65307
# define ARROW_UP 65362
# define ARROW_LEFT 65361
# define ARROW_DOWN 65364
# define ARROW_RIGHT 65363

# define FLOOR_PATH "./img/floor.xpm"
# define WALL_PATH "./img/wall.xpm"
# define PLAYER_PATH "./img/player.xpm"
# define COLLECTIBLE_PATH "./img/collectible.xpm"
# define EXIT_PATH "./img/exit.xpm"
# define ENEMY_RIGHT_PATH "./img/enemy_right.xpm"
# define ENEMY_LEFT_PATH "./img/enemy_left.xpm"

# define ARGS_ERR "Wrong number of arguments\n"
# define FILE_EXT_ERR "Wrong map file format\n"
# define FILE_PERMISSION_ERR "Wrong permissions, can't open map file\n"
# define MAP_SIZE_ERR "Map is not rectangular\n"
# define MAP_WALLS_ERR "Map must be surrounded by walls\n"
# define WRONG_CHAR_ERR "Map contains invalid characters\n"
# define MAP_START_ERR "Map must have a starting position (P character)\n"
# define MAP_EXIT_ERR "Map must have an exit\n"
# define MAP_COLLECTIBLES_ERR "Map must have at least one collectible\n"
# define MAP_PATH_ERR "Exit or collectible is not reachable\n"
# define MALLOC_ERR "Can't allocate memory\n"
# define OTHER_ERR "Something went wrong\n"

# include <unistd.h> // write, read, close
# include <stdlib.h> // malloc, free, exit, srand, rand
# include <fcntl.h> // open
# include <time.h> // time in seconds for random seed
# include "mlx/mlx.h"

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_enemy
{
	void	*enemy_left;
	void	*enemy_right;
}	t_enemy;

typedef struct s_img
{
	void		*wall;
	void		*floor;
	void		*player;
	void		*exit;
	void		*collectible;
	t_enemy		enemy;
}	t_img;

typedef struct s_player_pos
{
	unsigned int	col;
	unsigned int	row;
}	t_player_pos;

typedef struct s_map
{
	t_mlx				mlx;
	t_img				img;
	char				**map_data;
	t_player_pos		player_pos;
	int					width;
	int					height;
	unsigned int		items_to_collect;
}	t_map;

typedef struct s_map_checker
{
	unsigned int	start;
	unsigned int	collectibles;
	unsigned int	exits;
}	t_map_checker;

typedef struct s_file
{
	int		fd;
	char	*line;
}	t_file;

typedef struct s_game
{
	t_mlx			mlx;
	t_map			map;
	unsigned int	steps;
	int				exit;
}	t_game;

char	*get_next_line(int fd);

/* ---- Utils ------------------------- */

char	*ft_itoa(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strcpy(char *dst, char *src);
int		ft_strlen(const char *str, int type);

/* ---- Mandatory --------------------- */
void	display_error_exit(char *message);
void	map_symbols_checker(t_map *map);
void	is_ber_file(char *filename);
void	find_player(t_map *map, int *px, int *py);
void	map_size_init(t_map *map, char *ber);
void	map_init(t_map *map, char *ber);
void	flood_fill(t_map *map);
int		game_close(t_game *game);
int		game_win(t_game *game);
int		game_action(int keycode, t_game *game);
void	img_init(t_mlx *mlx, t_img *img);
void	img_to_win(t_game *game);
char	make_player_moves(t_map *map, int keycode, int exit);
void	free_map_data(t_map *map);

/* ---- Bonus-------------------------- */
void	game_lose_bonus(t_game *game);
void	put_enemy_bonus(t_map *map);
void	img_init_bonus(t_mlx *mlx, t_img *img);
void	img_to_win_bonus(t_game *game);
int		game_action_bonus(int keycode, t_game *game);
char	make_player_moves_bonus(t_map *map, int keycode, int exit);

#endif

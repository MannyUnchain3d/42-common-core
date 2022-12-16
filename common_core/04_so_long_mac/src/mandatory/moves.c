/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:55:43 by Manny             #+#    #+#             */
/*   Updated: 2022/12/13 15:06:43 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	find_player(t_map *map, int *px, int *py)
{
	int	row;
	int	col;

	row = -1;
	while (map->map_data[++row])
	{
		col = -1;
		while (map->map_data[row][++col])
		{
			if (map->map_data[row][col] == 'P')
			{
				*px = col;
				*py = row;
			}
		}
	}

}

static void	change_coordinates(int keycode, t_player_pos *old,
								t_player_pos *new)
{
	if (keycode == ARROW_UP)
	{
		new->col = old->col;
		new->row = old->row - 1;
	}
	if (keycode == ARROW_LEFT)
	{
		new->col = old->col - 1;
		new->row = old->row;
	}
	if (keycode == ARROW_DOWN)
	{
		new->col = old->col;
		new->row = old->row + 1;
	}
	if (keycode == ARROW_RIGHT)
	{
		new->col = old->col + 1;
		new->row = old->row;
	}
}

char	make_player_moves(t_map *map, int keycode, int exit)
{
	t_player_pos	old;
	t_player_pos	new;
	char			passed;

	old.row = map->player_pos.row;
	old.col = map->player_pos.col;
	change_coordinates(keycode, &old, &new);
	passed = '1';
	if (map->map_data[new.row][new.col] != '1')
	{
		passed = map->map_data[new.row][new.col];
		map->map_data[new.row][new.col] = 'P';
		map->map_data[old.row][old.col] = '0';
	}
	if (exit == FALSE && passed == 'E')
	{
		map->map_data[old.row][old.col] = 'P';
		map->map_data[new.row][new.col] = 'E';
	}
	return (passed);
}

int	game_action(int keycode, t_game *game)
{
	char	passed;

	if (keycode == KEY_ESC)
		game_close(game);
	if (keycode != ARROW_UP && keycode != ARROW_LEFT && keycode != ARROW_DOWN
		&& keycode != ARROW_RIGHT)
		return (0);
	if (game->map.items_to_collect == 0)
		game->exit = TRUE;
	passed = make_player_moves(&(game->map), keycode, game->exit);
	if (passed != '1' && !(game->exit == FALSE && passed == 'E'))
	{
		ft_putstr_fd("Number of moves: ", 0);
		ft_putnbr_fd(++(game->steps), 1);
		ft_putstr_fd("\n", 1);
	}
	if (passed == 'E' && game->map.items_to_collect == 0)
		game_win(game);
	img_to_win(game);
	return (0);
}

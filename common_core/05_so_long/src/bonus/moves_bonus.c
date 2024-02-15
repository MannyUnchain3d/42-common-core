/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:55:43 by Manny             #+#    #+#             */
/*   Updated: 2022/12/17 19:50:51 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	change_coordinates_bonus(int keycode, t_player_pos *old,
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

char	make_player_moves_bonus(t_map *map, int keycode, int exit)
{
	t_player_pos	old;
	t_player_pos	new;
	char			passed;

	old.row = map->player_pos.row;
	old.col = map->player_pos.col;
	change_coordinates_bonus(keycode, &old, &new);
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

int	game_action_bonus(int keycode, t_game *game)
{
	char	passed;

	if (keycode == KEY_ESC)
		game_close(game);
	if (keycode != ARROW_UP && keycode != ARROW_LEFT && keycode != ARROW_DOWN
		&& keycode != ARROW_RIGHT)
		return (0);
	if (game->map.items_to_collect == 0)
		game->exit = TRUE;
	passed = make_player_moves_bonus(&(game->map), keycode, game->exit);
	if (passed != '1' && !(game->exit == FALSE && passed == 'E'))
		++(game->steps);
	if (passed == 'E' && game->map.items_to_collect == 0)
		game_win(game);
	if (passed == 'N')
		game_lose_bonus(game);
	img_to_win_bonus(game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:55:43 by Manny             #+#    #+#             */
/*   Updated: 2022/11/30 20:01:33 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	change_coordinates(int keycode, t_player_position *old,
								t_player_position *new)
{
	if (keycode == ARROW_UP)
	{
		new->x = old->x;
		new->y = old->y - 1;
	}
	if (keycode == ARROW_LEFT)
	{
		new->x = old->x - 1;
		new->y = old->y;
	}
	if (keycode == ARROW_DOWN)
	{
		new->x = old->x;
		new->y = old->y + 1;
	}
	if (keycode == ARROW_RIGHT)
	{
		new->x = old->x + 1;
		new->y = old->y;
	}
}

char	make_player_moves(t_map *map, int keycode, int exit)
{
	t_player_position	old;
	t_player_position	new;
	char				passed;

	old.y = map->player_position.y;
	old.x = map->player_position.x;
	change_coordinates(keycode, &old, &new);
	passed = '1';
	if (map->map_data[new.y][new.x] != '1')
	{
		passed = map->map_data[new.y][new.x];
		map->map_data[new.y][new.x] = 'P';
		map->map_data[old.y][old.x] = '0';
	}
	if (exit == FALSE && passed == 'E')
	{
		map->map_data[old.y][old.x] = 'P';
		map->map_data[new.y][new.x] = 'E';
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
		ft_putstr_fd("MOVE COUNT: :", 1);
		ft_putnbr_fd(++(game->steps), 1);
		ft_putstr_fd("\n", 1);
	}
	if (passed == 'E' && game->map.items_to_collect == 0)
		game_win(game);
	img_to_win(game);
	return (0);
}
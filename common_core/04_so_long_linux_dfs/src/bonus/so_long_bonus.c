/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:53:15 by Manny             #+#    #+#             */
/*   Updated: 2022/12/05 01:44:36 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	params_init(t_game *game)
{
	game->steps = 0;
	game->exit = FALSE;
}

static int	update(t_game *game)
{
	img_to_win_bonus(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		display_error_exit(ARGS_ERR);
	params_init(&game);
	map_init(&game.map, argv[1]);
	game.mlx.ptr = mlx_init();
	game.mlx.win = mlx_new_window(game.mlx.ptr, game.map.width * CELL_SIZE,
			game.map.height * CELL_SIZE, "so_long");
	mlx_hook(game.mlx.win, 17, 0, game_close, (void *)&game);
	mlx_hook(game.mlx.win, 2, 1L<<0, game_action_bonus, (void *)&game);
	mlx_loop_hook(game.mlx.ptr, update, &game);
	img_init_bonus(&(game.mlx), &(game.map.img));
	put_enemy_bonus(&(game.map));
	img_to_win_bonus(&game);
	mlx_loop(game.mlx.ptr);
	return (0);
}

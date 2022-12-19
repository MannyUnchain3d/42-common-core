/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:53:15 by Manny             #+#    #+#             */
/*   Updated: 2022/12/17 02:44:54 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	params_init(t_game *game)
{
	game->steps = 0;
	game->exit = FALSE;
	game->map.map_data = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		display_error_exit(&game.map, ARGS_ERR);
	params_init(&game);
	map_init(&game.map, argv[1]);
	flood_fill(&game.map);
	game.mlx.ptr = mlx_init();
	game.mlx.win = mlx_new_window(game.mlx.ptr, game.map.width * CELL_SIZE,
			game.map.height * CELL_SIZE, "so_long");
	mlx_hook(game.mlx.win, 17, 0, game_close, (void *)&game);
	mlx_hook(game.mlx.win, 2, 1L << 0, game_action, (void *)&game);
	img_init(&(game.mlx), &(game.map.img));
	img_to_win(&game);
	mlx_loop(game.mlx.ptr);
	return (0);
}

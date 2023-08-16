/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:38:19 by Manny             #+#    #+#             */
/*   Updated: 2023/08/02 15:53:18 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_controls(void)
{
	printf(MAGENTA);
	printf(" ____ ____ ____ ____ ____ \n");
	printf("||C |||U |||B |||3 |||D ||\n");
	printf("||__|||__|||__|||__|||__||\n");
	printf("|/__\\|/__\\|/__\\|/__\\|/__\\|\n");
	printf(NC "\n");
	printf("Controls:\n");
	printf("WASD: Move\n");
	printf("LEFT and RIGHT: Rotate\n");
	printf("ESC: Exit\n");
	printf("M: Toggle minimap\n"); //ON Y CROIT ( ͡° ͜ʖ ͡°)
	printf("R: Toggle raycast\n"); //ON Y CROIT ( ͡° ͜ʖ ͡°)
	printf("T: Toggle textures\n"); //ON Y CROIT ( ͡° ͜ʖ ͡°)
	printf("G: Toggle grid\n"); //ON Y CROIT ( ͡° ͜ʖ ͡°)
	printf("H: Toggle HUD\n"); //ON Y CROIT ( ͡° ͜ʖ ͡°)
	printf("C: Toggle controls\n"); //ON Y CROIT ( ͡° ͜ʖ ͡°)
}

static int	parse_args(t_data *data, char **av)
{
	// ON Y CROIT ( ͡° ͜ʖ ͡°)
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (err_msg("Usage", ERR_USAGE, 1));
	if (parse_args(&data, av))
		return (1);
	init_data(&data);
	init_mlx(&data);
	init_textures(&data);
	print_controls();
	// ...
	// ...
	// ...
	// ...
	// ON Y CROIT ( ͡° ͜ʖ ͡°)
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:38:19 by Manny             #+#    #+#             */
/*   Updated: 2023/08/30 22:51:37 by etetopat         ###   ########.fr       */
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
}
	/* ON Y CROIT ( ͡° ͜ʖ ͡°)
	printf("M: Toggle minimap\n");
	printf("R: Toggle raycast\n"); 
	printf("T: Toggle textures\n");
	printf("G: Toggle grid\n");
	printf("H: Toggle HUD\n");
	printf("C: Toggle controls\n");
	*/

static int	parse_args(t_data *data, char **av)
{
	if (check_file(av[1], true) == FAILURE)
		clean_exit(data, FAILURE);

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
}

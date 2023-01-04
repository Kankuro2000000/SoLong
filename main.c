/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <vtasia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:33:59 by vtasia            #+#    #+#             */
/*   Updated: 2022/05/30 12:16:40 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{	
	t_game	game;

	game.map = open_and_fill_map(argv[1], argc, game);
	if (game.map == NULL)
		return (1);
	fill_content(&game);
	if (all_check(game.map, &game))
		return (1);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map_width * 64,
			game.map_height * 64, "so_long");
	sprites(&game);
	draw_map(game);
	mlx_hook(game.win, 2, 0, key_press, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}

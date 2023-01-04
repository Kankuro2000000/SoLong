/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <vtasia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:41:27 by vtasia            #+#    #+#             */
/*   Updated: 2022/05/30 11:35:50 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	foe_move_w(t_game *game)
{
	find_foe(game);
	if (game->map[game->enemy_y - 1][game->enemy_x] == '0')
	{
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->map[game->enemy_y - 1][game->enemy_x] = 'F';
	}
	if (game->map[game->enemy_y - 1][game->enemy_x] == 'P')
		lose_game(game);
	draw_map_foe(*game);
}

void	foe_move_s(t_game *game)
{
	find_foe(game);
	if (game->map[game->enemy_y + 1][game->enemy_x] == '0')
	{
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->map[game->enemy_y + 1][game->enemy_x] = 'F';
	}
	if (game->map[game->enemy_y + 1][game->enemy_x] == 'P')
		lose_game(game);
	draw_map_foe(*game);
}

void	foe_move_a(t_game *game)
{
	find_foe(game);
	if (game->map[game->enemy_y][game->enemy_x - 1] == '0')
	{
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->map[game->enemy_y][game->enemy_x - 1] = 'F';
	}
	if (game->map[game->enemy_y][game->enemy_x - 1] == 'P')
		lose_game(game);
	draw_map_foe(*game);
}

void	foe_move_d(t_game *game)
{
	find_foe(game);
	if (game->map[game->enemy_y][game->enemy_x + 1] == '0')
	{
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->map[game->enemy_y][game->enemy_x + 1] = 'F';
	}
	if (game->map[game->enemy_y][game->enemy_x + 1] == 'P')
		lose_game(game);
	draw_map_foe(*game);
}

void	foe_move(t_game *game)
{
	game->rand_num = ft_rand(game->rand_num);
	if (game->rand_num % 4 == 0)
		foe_move_w(game);
	if (game->rand_num % 4 == 1)
		foe_move_a(game);
	if (game->rand_num % 4 == 2)
		foe_move_s(game);
	if (game->rand_num % 4 == 3)
		foe_move_d(game);
}

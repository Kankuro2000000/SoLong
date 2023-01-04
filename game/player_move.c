/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <vtasia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:39:06 by vtasia            #+#    #+#             */
/*   Updated: 2022/05/26 19:10:49 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_move(t_game *game, int y, int x)
{
	game->map[game->player_y - y][game->player_x - x] = 'P';
	game->map[game->player_y][game->player_x] = '0';
	game->steps++;
}

int	move_w(t_game *game)
{
	find_player(game);
	if (game->map[game->player_y - 1][game->player_x] == '0')
		player_move(game, 1, 0);
	else if (game->map[game->player_y - 1][game->player_x] == 'C')
	{
		player_move(game, 1, 0);
		game->collect++;
	}
	else if (game->map[game->player_y - 1][game->player_x] == 'F')
		lose_game(game);
	else if (game->map[game->player_y - 1][game->player_x] == 'E'
		&& game->collect == game->collect_max)
	{
		player_move(game, 1, 0);
		game_over(game);
	}
	if (game->steps != game->steps_buff)
		print_steps(game->steps);
	draw_map_player(*game);
	return (0);
}

int	move_s(t_game *game)
{
	find_player(game);
	if (game->map[game->player_y + 1][game->player_x] == '0')
		player_move(game, -1, 0);
	else if (game->map[game->player_y + 1][game->player_x] == 'C')
	{
		player_move(game, -1, 0);
		game->collect++;
	}
	else if (game->map[game->player_y + 1][game->player_x] == 'F')
		lose_game(game);
	else if (game->map[game->player_y + 1][game->player_x] == 'E'
		&& game->collect == game->collect_max)
	{
		player_move(game, -1, 0);
		game_over(game);
	}
	if (game->steps != game->steps_buff)
		print_steps(game->steps);
	draw_map_player(*game);
	return (0);
}

int	move_a(t_game *game)
{
	find_player(game);
	if (game->map[game->player_y][game->player_x - 1] == '0')
		player_move(game, 0, 1);
	else if (game->map[game->player_y][game->player_x - 1] == 'C')
	{
		player_move(game, 0, 1);
		game->collect++;
	}
	else if (game->map[game->player_y][game->player_x - 1] == 'F')
		lose_game(game);
	else if (game->map[game->player_y][game->player_x - 1] == 'E'
		&& game->collect == game->collect_max)
	{
		player_move(game, 0, 1);
		game_over(game);
	}
	if (game->steps != game->steps_buff)
		print_steps(game->steps);
	draw_map_player(*game);
	return (0);
}

int	move_d(t_game *game)
{
	find_player(game);
	if (game->map[game->player_y][game->player_x + 1] == '0')
		player_move(game, 0, -1);
	else if (game->map[game->player_y][game->player_x + 1] == 'C')
	{
		player_move(game, 0, -1);
		game->collect++;
	}
	else if (game->map[game->player_y][game->player_x + 1] == 'F')
		lose_game(game);
	else if (game->map[game->player_y][game->player_x + 1] == 'E'
		&& game->collect == game->collect_max)
	{
		player_move(game, 0, -1);
		game_over(game);
	}
	if (game->steps != game->steps_buff)
		print_steps(game->steps);
	draw_map_player(*game);
	return (0);
}

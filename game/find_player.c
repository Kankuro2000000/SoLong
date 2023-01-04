/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <vtasia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:46:26 by vtasia            #+#    #+#             */
/*   Updated: 2022/05/30 11:30:35 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	game->steps_buff = game->steps;
	game->player_x_buff = game->player_x;
	game->player_y_buff = game->player_y;
	while (game->map[i] != NULL)
	{
		k = 0;
		while (game->map[i][k] != '\0')
		{
			if (game->map[i][k] == 'P')
			{
				game->player_y = i;
				game->player_x = k;
				return ;
			}
			k++;
		}
		i++;
	}
}

int	key_press(int key_code, t_game *game)
{
	if (key_code == 53)
		exit_game(game);
	if (key_code == 13)
		move_w(game);
	if (key_code == 0)
		move_a(game);
	if (key_code == 1)
		move_s(game);
	if (key_code == 2)
		move_d(game);
	return (0);
}

int	find_max_coin(t_game game)
{
	int	i;
	int	k;
	int	coin;

	i = 0;
	coin = 0;
	while (game.map[i] != NULL)
	{
		k = 0;
		while (game.map[i][k] != '\0')
		{
			if (game.map[i][k] == 'C')
				coin++;
			k++;
		}
		i++;
	}
	return (coin);
}

void	fill_content(t_game *game)
{
	game->map_height = find_map_height(*game);
	game->map_width = find_map_width(*game);
	game->collect = 0;
	game->collect_max = find_max_coin(*game);
	game->steps = 0;
	game->anim = 0;
	game->defeat_anim = 0;
	game->rand_num = 0;
}

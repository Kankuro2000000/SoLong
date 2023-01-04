/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <vtasia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:43:30 by vtasia            #+#    #+#             */
/*   Updated: 2022/05/30 12:08:30 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	find_foe(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	game->steps_buff = game->steps;
	while (game->map[i] != NULL)
	{
		k = 0;
		while (game->map[i][k] != '\0')
		{
			if (game->map[i][k] == 'F')
			{
				game->enemy_y = i;
				game->enemy_x = k;
				return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}

void	foe_animation(t_game *game)
{
	if ((game->anim % 100 > 0 && game->anim % 100 < 50))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->enemy_2,
			game->enemy_x * 64, game->enemy_y * 64);
			game->defeat_anim = 1;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->enemy,
			game->enemy_x * 64, game->enemy_y * 64);
			game->defeat_anim = 0;
	}
}

void	player_animation(t_game *game)
{
	if ((game->anim % 100 > 0 && game->anim % 100 < 50))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player_2,
			game->player_x * 64, game->player_y * 64);
		game->defeat_anim = 1;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			game->player_x * 64, game->player_y * 64);
		game->defeat_anim = 0;
	}
}

int	update(t_game *game)
{
	char	*str;

	str = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->win, 24, 24, -1, str);
	find_player(game);
	player_animation(game);
	if (find_foe(game))
	{
		foe_animation(game);
		if (game->anim % 20 == 0)
			foe_move(game);
	}
	free(str);
	game->anim++;
	return (0);
}

int	ft_rand(int num)
{
	while (num > 10009)
	{
		num = num / 6;
		num = num * 2;
		num = num / 3;
	}
	num += 105;
	num *= 9;
	num /= 3;
	num += 4;
	return (num * 13);
}

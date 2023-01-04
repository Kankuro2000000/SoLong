/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <vtasia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:03:56 by vtasia            #+#    #+#             */
/*   Updated: 2022/05/26 19:05:52 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sprites(t_game *game)
{
	game->ground = mlx_xpm_file_to_image(game->mlx, "./sprites/ground.xpm",
			&game->img_width, &game->img_height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm",
			&game->img_width, &game->img_height);
	game->player = mlx_xpm_file_to_image(game->mlx, "./sprites/player_1.xpm",
			&game->img_width, &game->img_height);
	game->player_2 = mlx_xpm_file_to_image(game->mlx, "./sprites/player_2.xpm",
			&game->img_width, &game->img_height);
	game->coin = mlx_xpm_file_to_image(game->mlx, "./sprites/coin.xpm",
			&game->img_width, &game->img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./sprites/exit.xpm",
			&game->img_width, &game->img_height);
	game->enemy = mlx_xpm_file_to_image(game->mlx, "./sprites/enemy_1.xpm",
			&game->img_width, &game->img_height);
	game->enemy_2 = mlx_xpm_file_to_image(game->mlx, "./sprites/enemy_2.xpm",
			&game->img_width, &game->img_height);
}

void	draw_element(t_game game, int hei, int wid)
{
	if (game.map[hei][wid] == '1')
		mlx_put_image_to_window(game.mlx, game.win, game.wall,
			wid * 64, hei * 64);
	else if (game.map[hei][wid] == 'C')
		mlx_put_image_to_window(game.mlx, game.win, game.coin,
			wid * 64, hei * 64);
	else if (game.map[hei][wid] == 'P' && game.defeat_anim == 0)
		mlx_put_image_to_window(game.mlx, game.win, game.player,
			wid * 64, hei * 64);
	else if (game.map[hei][wid] == 'E')
		mlx_put_image_to_window(game.mlx, game.win, game.exit,
			wid * 64, hei * 64);
	else if (game.map[hei][wid] == 'F' && game.defeat_anim == 0)
		mlx_put_image_to_window(game.mlx, game.win, game.enemy,
			wid * 64, hei * 64);
	else
		mlx_put_image_to_window(game.mlx, game.win, game.ground,
			wid * 64, hei * 64);
}

void	draw_map(t_game game)
{
	int	hei;
	int	wid;

	hei = 0;
	while (hei < game.map_height)
	{
		wid = 0;
		while (wid < game.map_width)
		{
			draw_element(game, hei, wid);
			wid++;
		}
		hei++;
	}
}

void	draw_map_foe(t_game game)
{
	int	hei;
	int	wid;

	hei = 0;
	while (hei < game.map_height)
	{
		wid = 0;
		while (wid < game.map_width)
		{
			if (game.map[hei][wid] == 'F' && game.defeat_anim == 0)
				mlx_put_image_to_window(game.mlx, game.win, game.enemy,
					wid * 64, hei * 64);
			else if (game.map[hei][wid] == 'F' && game.defeat_anim == 1)
				mlx_put_image_to_window(game.mlx, game.win, game.enemy_2,
					wid * 64, hei * 64);
			else if (game.map[hei][wid] == '0')
				mlx_put_image_to_window(game.mlx, game.win, game.ground,
					wid * 64, hei * 64);
			wid++;
		}
		hei++;
	}
}

void	draw_map_player(t_game game)
{
	int	hei;
	int	wid;

	hei = 0;
	while (hei < game.map_height)
	{
		wid = 0;
		while (wid < game.map_width)
		{
			if (game.map[hei][wid] == 'P' && game.defeat_anim == 0)
				mlx_put_image_to_window(game.mlx, game.win, game.player,
					wid * 64, hei * 64);
			else if (game.map[hei][wid] == '0')
				mlx_put_image_to_window(game.mlx, game.win, game.ground,
					wid * 64, hei * 64);
			wid++;
		}
		hei++;
	}
	mlx_put_image_to_window(game.mlx, game.win, game.wall, 0, 0);
}

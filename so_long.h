/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <vtasia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:32:52 by vtasia            #+#    #+#             */
/*   Updated: 2022/05/30 11:30:24 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*ground;
	void	*wall;
	void	*player;
	void	*player_2;
	void	*coin;
	void	*exit;
	void	*enemy;
	void	*enemy_2;
	int		rand_num;
	int		player_x;
	int		player_y;
	int		player_x_buff;
	int		player_y_buff;
	int		collect;
	int		collect_max;
	int		steps;
	int		steps_buff;
	int		anim;
	int		defeat_anim;
	int		enemy_x;
	int		enemy_y;
	int		img_width;
	int		img_height;
	int		map_width;
	int		map_height;
}	t_game;

/*checks*/
/*check_contain.c*/

int		check_contain_e(char **str);
int		check_contain_p(char **str);
int		check_contain_c(char **str);
int		check_contain(char **str);

/*check_surrounded.c*/

int		check_floor(char *str);
int		check_frs_lst(char **str, int wid);
int		check_wall(char *str, int len);
int		check_surrounded(char **str, int len, int hei);
int		check_separator(char *str);

/*checks.c*/

int		check_name(char *str);
int		check_rectangle(char **str, int len, int hei);
int		ft_composed(char c);
int		check_composed(char **str);
int		all_check(char **str, t_game *game);

/*draw_map*/
/*additional_functions.c*/

int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_sep(char c);
void	ft_putstr(char *str);
char	**error_mes(char *str);

/*additional_functions_2.c*/

int		ft_num(int n);
char	*ft_itoa(int n);
void	print_steps(int steps);
int		find_map_width(t_game game);
int		find_map_height(t_game game);

/*draw_map.c*/

void	sprites(t_game *game);
void	draw_element(t_game game, int hei, int wid);
void	draw_map(t_game game);
void	draw_map_foe(t_game game);
void	draw_map_player(t_game game);

/*ft_split.c*/

int		ft_size(char *str);
int		ft_wordlen(char *str);
char	*malloc_word(char *str);
char	**free_split(char **map, int i);
char	**ft_split(char *str);

/*open_and_fill_map.c*/

void	free_map(t_game *game);
int		count_arr_len(char *file);
char	**malloc_arr(char *file, int arr_len);
char	**open_and_fill_map(char *file, int argc, t_game game);

/*game*/
/*end_game.c*/

int		exit_game(t_game *game);
void	game_over(t_game *game);
void	lose_game(t_game *game);

/*find_player.c*/

void	find_player(t_game *game);
int		find_max_coin(t_game game);
void	fill_content(t_game *game);
int		key_press(int key_code, t_game *game);

/*player_move.c*/

void	player_move(t_game *game, int y, int x);
int		move_w(t_game *game);
int		move_s(t_game *game);
int		move_a(t_game *game);
int		move_d(t_game *game);

/*bonus*/
/*animation.c*/

int		find_foe(t_game *game);
void	foe_animation(t_game *game);
void	player_animation(t_game *game);
int		update(t_game *game);
int		ft_rand(int num);

/*foe_move.c*/

void	foe_move_w(t_game *game);
void	foe_move_s(t_game *game);
void	foe_move_a(t_game *game);
void	foe_move_d(t_game *game);
void	foe_move(t_game *game);

#endif
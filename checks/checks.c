/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <vtasia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:51:11 by vtasia            #+#    #+#             */
/*   Updated: 2022/05/30 12:20:32 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strcmp(".ber", str + len - 4))
		return (1);
	return (0);
}

int	check_rectangle(char **str, int len, int hei)
{
	int	i;
	int	check_len;

	i = 0;
	while (i < hei)
	{
		check_len = ft_strlen(str[i]);
		if (check_len != len)
		{
			ft_putstr("Error\nThe map must be rectangular\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_composed(char c)
{
	return (c == '1' || c == '0' || c == 'C'
		|| c == 'E' || c == 'P');
}

int	check_composed(char **str)
{
	int	i;
	int	k;

	i = 0;
	while (str[i] != NULL)
	{
		k = 0;
		while (str[i][k] != '\0')
		{
			if (!ft_composed(str[i][k]))
			{
				ft_putstr("Error\nThe map contains forbidden symbols\n");
				return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}

int	all_check(char **str, t_game *game)
{
	if (check_rectangle(str, game->map_width, game->map_height))
	{
		free_map(game);
		return (1);
	}
	if (check_composed(str))
	{
		free_map(game);
		return (1);
	}
	if (check_contain(str))
	{
		free_map(game);
		return (1);
	}
	if (check_surrounded(str, game->map_width, game->map_height))
	{
		free_map(game);
		return (1);
	}
	return (0);
}

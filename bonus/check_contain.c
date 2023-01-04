/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <vtasia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:58:15 by vtasia            #+#    #+#             */
/*   Updated: 2022/05/26 19:00:48 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_contain_e(char **str)
{
	int	i;
	int	k;

	i = 0;
	while (str[i] != NULL)
	{
		k = 0;
		while (str[i][k] != '\0')
		{
			if (str[i][k] == 'E')
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	check_contain_p(char **str)
{
	int	i;
	int	k;
	int	player;

	player = 0;
	i = 0;
	while (str[i] != NULL)
	{
		k = 0;
		while (str[i][k] != '\0')
		{
			if (str[i][k] == 'P')
				player++;
			k++;
		}
		i++;
	}
	if (player > 1)
		return (2);
	if (player == 0)
		return (1);
	return (0);
}

int	check_contain_c(char **str)
{
	int	i;
	int	k;

	i = 0;
	while (str[i] != NULL)
	{
		k = 0;
		while (str[i][k] != '\0')
		{
			if (str[i][k] == 'C')
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	check_contain(char **str)
{
	if (check_contain_e(str))
	{
		ft_putstr("Error\nThe map must contain an exit\n");
		return (1);
	}
	if (check_contain_p(str) == 1)
	{
		ft_putstr("Error\nThe map must contain a player\n");
		return (1);
	}
	if (check_contain_p(str) == 2)
	{
		ft_putstr("Error\nThe map must contain only one player\n");
		return (1);
	}
	if (check_contain_c(str))
	{
		ft_putstr("Error\nThe map must contain a collectible\n");
		return (1);
	}
	return (0);
}

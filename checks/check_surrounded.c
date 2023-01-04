/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surrounded.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <vtasia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:59:30 by vtasia            #+#    #+#             */
/*   Updated: 2022/05/26 19:00:53 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_separator(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_floor(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_frs_lst(char **str, int wid)
{
	return (check_floor(str[0]) || check_floor(str[wid - 1]));
}

int	check_wall(char *str, int len)
{
	if (str[0] != '1' || str[len - 1] != '1')
		return (1);
	return (0);
}

int	check_surrounded(char **str, int len, int hei)
{
	int	i;
	int	err;

	i = 1;
	err = 0;
	if (check_frs_lst(str, hei))
		err = 1;
	while (i < hei - 1)
	{
		if (check_wall(str[i], len))
			err = 1;
		i++;
	}
	if (err != 0)
	{
		ft_putstr("Error\nThe map must be closed/surrounded by walls\n");
		return (1);
	}
	return (0);
}

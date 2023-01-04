/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <vtasia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:21:30 by vtasia            #+#    #+#             */
/*   Updated: 2022/05/26 19:05:44 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_num(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*buff;
	int		i;
	long	nb;

	i = ft_num(n);
	nb = n;
	buff = (char *)malloc(sizeof(char) * (i + 1));
	if (!buff)
		return (NULL);
	if (nb < 0)
	{
		buff[0] = '-';
		nb *= -1;
	}
	buff[i] = '\0';
	if (nb == 0)
		buff[0] = '0';
	while (nb)
	{
		buff[i - 1] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (buff);
}

void	print_steps(int steps)
{
	char	*str;

	str = ft_itoa(steps);
	ft_putstr(str);
	write(1, "\n", 1);
	free(str);
}

int	find_map_width(t_game game)
{
	return (ft_strlen(game.map[0]));
}

int	find_map_height(t_game game)
{
	int	i;

	i = 0;
	while (game.map[i] != NULL)
		i++;
	return (i);
}

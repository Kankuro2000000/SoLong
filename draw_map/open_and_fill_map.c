/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_fill_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <vtasia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:14:51 by vtasia            #+#    #+#             */
/*   Updated: 2022/05/26 19:06:01 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

int	count_arr_len(char *file)
{
	int		arr_len;
	int		fd;
	int		readcount;
	char	c;

	arr_len = 0;
	readcount = 1;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	while (readcount != 0)
	{
		readcount = read(fd, &c, 1);
		if (readcount < 0)
			return (-1);
		arr_len++;
	}
	close(fd);
	return (arr_len - 1);
}

char	**malloc_arr(char *file, int arr_len)
{
	int		fd;
	int		readcount;
	char	str[1000];
	char	**map;

	readcount = 1;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (NULL);
	read(fd, &str, arr_len);
	close (fd);
	str[arr_len] = '\0';
	if (check_separator(str))
		return (error_mes("Error\nExtra delimiters found\n"));
	map = ft_split(str);
	if (!map)
		return (error_mes("Error\nMemory allocation error\n"));
	return (map);
}

char	**open_and_fill_map(char *file, int argc, t_game game)
{
	char	**map;
	int		arr_len;

	if (argc != 2)
	{
		ft_putstr("Error\nInvalid number of arguments\n");
		return (NULL);
	}
	if (check_name(file))
	{
		ft_putstr("Error\nMap name must end with .ber\n");
		return (NULL);
	}
	arr_len = count_arr_len(file);
	if (arr_len == -1)
	{
		ft_putstr("Error\nFile cannot be opened or read\n");
		return (NULL);
	}
	map = malloc_arr(file, arr_len);
	if (!map)
		return (NULL);
	return (map);
}

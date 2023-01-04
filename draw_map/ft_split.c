/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <vtasia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:37:28 by vtasia            #+#    #+#             */
/*   Updated: 2022/05/26 19:05:56 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_size(char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		while (str[i] && ft_sep(str[i]))
			i++;
		if (str[i] && !ft_sep(str[i]))
			res++;
		while (str[i] && !ft_sep(str[i]))
			i++;
	}
	return (res);
}

int	ft_wordlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !ft_sep(str[i]))
		i++;
	return (i);
}

char	*malloc_word(char *str)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = ft_wordlen(str);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**free_split(char **map, int i)
{
	while (map[i--])
		free(map[i]);
	return (NULL);
}

char	**ft_split(char *str)
{
	char	**res;
	int		size;
	int		i;

	i = 0;
	size = ft_size(str);
	res = malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	while (i < size)
	{
		while (*str && ft_sep(*str))
			str++;
		res[i] = malloc_word(str);
		if (res[i] == NULL)
			return (free_split(res, i));
		while (*str && !ft_sep(*str))
			str++;
		i++;
	}
	res[i] = NULL;
	return (res);
}

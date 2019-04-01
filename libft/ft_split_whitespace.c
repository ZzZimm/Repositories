/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:21:59 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 14:28:40 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str > 32)
		str++;
	if (*str)
		return (1 + count_words(str));
	return (*(str - 1) > 32 ? 1 : 0);
}

static int		*word_beg(const char *str)
{
	int *arr;
	int i;
	int j;

	i = 0;
	j = -1;
	if (!(arr = (int *)malloc(sizeof(int) * count_words(str))))
		return (NULL);
	while (++j < count_words(str))
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		if (str[i] > 32)
			arr[j] = i;
		while (str[i] > 32)
			i++;
	}
	return (arr);
}

static int		*word_end(const char *str)
{
	int *arr;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(arr = (int *)malloc(sizeof(int) * count_words(str))))
		return (NULL);
	while (j < count_words(str))
	{
		while (str[i] && (str[i] < 9 || str[i] > 13) && str[i] != ' ')
			i++;
		if (str[i - 1] > 32 && str[i] <= 32)
		{
			arr[j] = i;
			j++;
		}
		while (str[i] <= 32)
			i++;
	}
	return (arr);
}

char			**ft_split_whitespace(const char *str)
{
	char	**tab;
	int		*beg;
	int		*end;
	int		i;
	int		j;

	j = -1;
	beg = word_beg(str);
	end = word_end(str);
	if (!(tab = (char **)malloc(sizeof(char *) * (count_words(str) + 1))))
		return (NULL);
	while (++j < count_words(str))
	{
		i = -1;
		if (!(tab[j] = (char *)malloc(sizeof(char) * (end[j] - beg[j] + 1))))
			return (NULL);
		while (++i < end[j] - beg[j])
			tab[j][i] = str[beg[j] + i];
		tab[j][i] = '\0';
	}
	tab[j] = NULL;
	return (tab);
}

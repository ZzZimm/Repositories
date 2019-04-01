/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:09:07 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 15:37:30 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words_c(char const *str, char c)
{
	if (!*str)
		return (0);
	while (*str == c)
		str++;
	while (*str && *str != c)
		str++;
	if (*str)
		return (1 + count_words_c(str, c));
	return (*(str - 1) != c ? 1 : 0);
}

static int		*word_beg_c(char const *str, char c)
{
	int *arr;
	int i;
	int j;

	i = 0;
	j = -1;
	if (!(arr = (int *)malloc(sizeof(int) * count_words_c(str, c))))
		return (NULL);
	while (++j < count_words_c(str, c))
	{
		while (str[i] == c)
			i++;
		if (str[i] != c)
			arr[j] = i;
		while (str[i] != c)
			i++;
	}
	return (arr);
}

static int		*word_end_c(char const *str, char c)
{
	int *arr;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(arr = (int *)malloc(sizeof(int) * count_words_c(str, c))))
		return (NULL);
	while (str[i] == c)
		i++;
	while (j < count_words_c(str, c))
	{
		while (str[i] && str[i] != c)
			i++;
		if ((str[i] == c && str[i - 1] != c) || !str[i])
		{
			arr[j] = i;
			j++;
		}
		while (str[i] == c)
			i++;
	}
	return (arr);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		*beg;
	int		*end;
	int		i;
	int		j;

	j = -1;
	if (!str ||
		!(tab = (char **)malloc(sizeof(char *) * (count_words_c(str, c) + 1))))
		return (NULL);
	beg = word_beg_c(str, c);
	end = word_end_c(str, c);
	while (++j < count_words_c(str, c))
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

#include "libft.h"

/*
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

char	**ft_strsplit(char const *str, char c)
{
	char **tab;
	int *beg;
	int *end;
	int i;
	int j;

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
*/

#include <stdlib.h>

static unsigned int	ft_wordlen(unsigned int index, char const *s, char c)
{
	unsigned int i;

	i = 0;
	while (s[index] && s[index] != c)
	{
		index++;
		i++;
	}
	return (i);
}

static unsigned int	ft_wordcount(char const *s, char c)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while (s[i] == c)
	{
		if (s[i + 1] == '\0')
			return (0);
		i++;
	}
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			**tab;

	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * ft_wordcount(s, c) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		if (!(tab[j] = (char *)malloc(sizeof(char) * ft_wordlen(i, s, c) + 1)))
			return (NULL);
		while (s[i] && s[i] != c && ft_wordcount(s, c) > 0)
			tab[j][k++] = s[i++];
		tab[j][k] = '\0';
		j++;
	}
	tab[ft_wordcount(s, c)] = NULL;
	return (tab);
}


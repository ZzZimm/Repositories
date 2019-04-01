#include "libft.h"

int		count_words_c(char const *str, char c)
{
	while (*str == c)
		str++;
	while (*str && *str != c)
		str++;
	return *str ? 1 + count_words_c(str, c) : *(str - 1) != c ? 1: 0;
}

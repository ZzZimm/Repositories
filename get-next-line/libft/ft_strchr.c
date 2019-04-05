#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	while (s[i] != c && s[i])
		i++;
	if (i == len && c != '\0')
		return (NULL);
	return ((char *)s + i);
}

#include "libft.h"

char *ft_strndup(char *src, size_t n)
{
	char *dest;
	int i;

	i = -1;
	if(!(dest = (char *)malloc(sizeof(*dest) * (n + 1))))
		return (NULL);
	while (src[++i] && n--)
		dest[i] = src[i];
	dest[i] = '\0';
	return(dest);
}

#include "libft.h"

char *ft_strdup(char *src)
{
	char *dest;
	int i;

	i = -1;
	if(!(dest = (char *)malloc(sizeof(*dest) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return(dest);
}

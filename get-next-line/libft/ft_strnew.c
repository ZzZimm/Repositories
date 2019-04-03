#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if(!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(str, size);
	return (str);
}

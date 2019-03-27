#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *new;
	size_t len;

	len = ft_strlen((char *)s);
	if(!(new = ft_strnew(len)))
		return (NULL);
	while (*s)
		*new++ = f(*s++);
	return (new - len);
}
	

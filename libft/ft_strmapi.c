#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *new;
	size_t len;
	size_t i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	if(!(new = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (s[++i])
		new[i] = f(i,s[i]);
	return (new);
}
	

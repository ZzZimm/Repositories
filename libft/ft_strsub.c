#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if(!s || !(sub = ft_strnew(len)))
		return (NULL);
	sub = ft_strncpy(sub, s + start, len);
	return (sub);
}

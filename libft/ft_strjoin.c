#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *sub;
	
	if (!s1 || !s2)
		return (NULL);
	if (!(sub = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2))))
		return (NULL);
	sub = ft_strcat(sub, s1);
	sub = ft_strcat(sub, s2);
	return (sub);
}

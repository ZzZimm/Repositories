#include <stdlib.h>
void	*ft_memchr(const char *s, int c, size_t n)
{
	while (n--)
	{
		if (*((unsigned char *)s) != (unsigned char)c)
			s++;
		else
			return ((void *)s);
	}
	return (NULL);
}

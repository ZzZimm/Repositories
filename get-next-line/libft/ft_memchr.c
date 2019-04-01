#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char c1;

	c1 = (unsigned char)c;
	while (n-- && *((unsigned char *)s))
	{
		if (*((unsigned char *)s) == c1) 
			return ((void *)s);
		s++;
	}
	return (NULL);
}

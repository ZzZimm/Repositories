#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;
	unsigned char c1;

	i = 0;
	c1 = (unsigned char)c;
	while (i < n)
	{	
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == c1)
			return (dst + i + 1);
		i++;
	}

	return (NULL);
}

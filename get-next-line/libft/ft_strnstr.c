#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int i[2];
	
	i[0] = 0;
	while (*haystack && i[0]++ <= n)
	{
		i[1] = 0;
		while (needle[i[1]] && needle[i[1]] == haystack[i[1]])
			i[1]++;
		if (needle[i[1]] == '\0' && i[1] + i[0] - 1 <= n)
			return ((char *)haystack);
		haystack++;
	}
	return *needle == '\0' ? (char *)haystack : NULL;
}

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	
	while (*haystack)
	{
		i = 0;
		while (needle[i] && needle[i] == haystack[i])
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return *needle == '\0' ? (char *)haystack : NULL;
}

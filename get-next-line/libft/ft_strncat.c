#include "libft.h"
#include <stdio.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i[3];
	
	i[0] = -1;
	i[1] = 0;
	i[2] = ft_strlen(s1);
	while (s2[++i[0]] && i[1]++ < n)
		s1[i[0] + i[2]] = s2[i[0]];
	s1[i[0] + i[2]] = '\0';
	return (s1);
}

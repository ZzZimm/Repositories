#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int i[2];
	
	i[0] = -1;
	i[1] = ft_strlen(s1);
	while (s2[++i[0]])
		s1[i[0] + i[1]] = s2[i[0]];
	s1[i[0] + i[1]] = '\0';
	return (s1);
}

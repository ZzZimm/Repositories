#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char *trim;
	size_t i;
	size_t len;

	i = 0;
	if (!s)
		return (NULL);
	while ((*s >= 9 && *s <= 17) || *s == ' ')
		s++;
	len = ft_strlen((char *)s);
	if (!len)
		return (ft_strnew(1));
	while ((s[len - 1] >= 9 && s[len - 1] <= 17) || s[len - 1] == ' ')
		 len--;
	if(!(trim = ft_strnew(len)))
		return (NULL);
	while (i < len) 
		 trim[i++] = *s++;
	return (trim);
}

#include "libft.h"

void	ft_strdel(char **as)
{
	if(!as)
		return;
	free(*as);
	*as = NULL;
}

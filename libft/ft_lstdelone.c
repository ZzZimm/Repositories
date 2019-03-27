#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		(*alst)->content_size = 0;
		free(*alst);
	}
	*alst = NULL;
}

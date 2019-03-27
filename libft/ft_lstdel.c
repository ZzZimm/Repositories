#include "libft.h"

void ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		(*alst)->content_size = 0;
		free(*alst);
		*alst = (*alst)->next;
	}
	*alst = NULL;
}

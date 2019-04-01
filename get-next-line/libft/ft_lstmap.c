#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *start;

	start = NULL;
	new = NULL;
	if(lst && f)
	{
		new = f(lst);
		start = new;
		lst = lst->next;
		while (lst)
		{
			new->next = f(lst);
			new = new->next;
			lst = lst->next;
		}
		new->next = NULL;
	}
	return (start);
}

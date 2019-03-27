#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *list;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new = NULL;
//	*new = ft_lstnew(lst->content, lst->content_size);
	while (lst)
	{
//		(*new)->next = ft_lstnew(lst->content, lst->content_size);
	//	ft_lstadd(&new, f(ft_lstnew(lst->content,lst->content_size)));
		new->next = ft_lstnew(lst->content, lst->content_size);
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (new);
}

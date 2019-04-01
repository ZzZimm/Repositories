#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static void ft_push_new(t_list **lst) 
{ 
    t_list	*new_node; 
	
	new_node = (t_list *)malloc(sizeof(t_list)); 
    new_node->next = (*lst); 
    new_node->prev = NULL; 
    if ((*lst)) 
        (*lst)->prev = new_node; 
    (*lst) = new_node; 
} 

static void ft_fill(int fd, t_list **lst)
{
	char buf[BUFF_SIZE];
	
	if (!(*lst = (t_list *)malloc(sizeof(t_list))))
		return (0);
	(*lst)->content = ft_strnew(BUFF_SIZE);
	(*lst)->content_size = 0;
	(*lst)->line_number = 0;
	(*lst)->fd = fd;
	while(read(fd,buf,BUFF_SIZE))
	{
		(*lst)->content = ft_strncat(ft_strndup((*lst)->content
		, (*lst)->content_size + BUFF_SIZE), buf, BUFF_SIZE);
		(*lst)->content_size = (*lst)->content_size + BUFF_SIZE;
	}
	printf("%s\n", (lst*)->content);
}


int		get_next_line(int const fd, char **line)
{
	static t_list *lst;
	char buf[BUFF_SIZE];

	if (&(lst->content))
	{
		if (lst->fd != fd)
		{
			printf("premier lst : %p\n", lst);
			ft_push_new(&lst);
			printf("suivant : %p\n", lst);
			printf("suivant adresse lst->content : %p\n", &(lst->content));
			printf("valeur lst->content : %s\n", lst->content);
		}
	}
	if (!&(lst->content))
	{
		printf("je suis la");
		if (!(lst = (t_list *)malloc(sizeof(t_list))))
			return (0);
		lst->content = ft_strnew(BUFF_SIZE);
		lst->content_size = 0;
		lst->line_number = 0;
		lst->fd = fd;
		while(read(fd,buf,BUFF_SIZE))
		{
			lst->content = ft_strncat(ft_strndup(lst->content
			, lst->content_size + BUFF_SIZE), buf, BUFF_SIZE);
			lst->content_size = lst->content_size + BUFF_SIZE;
		}
	}
	printf("%s\n", lst->content);
	*line = ft_strsplit(lst->content, '\n')[lst->line_number];
	lst->line_number += 1;

	return (0);
}

int main (int ac, char **av)
{
	int fd1;
	int fd2;
	char *output;

	if (ac >= 2)
	{
		fd1 = open(av[1], O_RDONLY);
		get_next_line(fd1, &output);
		printf("%s\n", output);
		get_next_line(fd1, &output);
		printf("%s\n", output);
		get_next_line(fd1, &output);
		printf("%s\n", output);
		get_next_line(fd1, &output);
		printf("%s\n", output);
		fd2 = open(av[2], O_RDONLY);
		get_next_line(fd2, &output);
		printf("%s\n", output);
		get_next_line(fd2, &output);
		printf("%s\n", output);
		close(fd1);
		close(fd2);
	}
	return (0);
}

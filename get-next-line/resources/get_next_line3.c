#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

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
	
	(*lst)->content = ft_strnew(BUFF_SIZE);
	(*lst)->content_size = 0;
	(*lst)->line_number = 0;
	(*lst)->fd = fd;
	while(read(fd,buf,BUFF_SIZE))
	{
    printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
//		printf("%p\n", (*lst)->content);
//		printf("%s\n", buf);
	//	getchar();
		(*lst)->content = ft_strncat(ft_strndup((*lst)->content
		, (*lst)->content_size + BUFF_SIZE), buf, BUFF_SIZE);
		(*lst)->content_size = (*lst)->content_size + BUFF_SIZE;
	}
	printf("fill termine\n");
}

t_list	*detect_fd(int fd, t_list *lst)
{
	int i;
	t_list *head;

	i = 0;
	head = lst;
	while (lst)
	{
		if (lst->fd == fd)
			return(lst);
		lst = lst->next;
		i++;
	}
	return (head);
}


int		get_next_line(int const fd, char **line)
{
	static t_list *lst;
	t_list *head;

	if (!&(lst->content))
	{
		if (!(lst = (t_list *)malloc(sizeof(t_list))))
			return 0;
		ft_fill(fd, &lst);
	}
	if (&(lst->content))
	{
		if (lst->fd != fd)
		{
			if(lst->next && lst->next->fd == fd)
			{
				lst = lst->next;
				printf("passage no %zu\n", lst->line_number);
				*line = ft_strsplit(lst->content, '\n')[lst->line_number];
				return(0);
			}
			else
			ft_push_new(&lst);
			ft_fill(fd, &lst);
		}
	}
	printf("passage no %zu\n", lst->line_number);
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
		fd2 = open(av[2], O_RDONLY);
		get_next_line(fd2, &output);
		printf("%s\n", output);
		get_next_line(fd2, &output);
		printf("%s\n", output);
		get_next_line(fd2, &output);
		printf("%s\n", output);
		get_next_line(fd1, &output);
		printf("%s\n", output);
		close(fd1);
		close(fd2);
	}
	return (0);
}

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
	while(read(fd,buf,BUFF_SIZE) > 0)
	{
		buf[ft_strlen(buf)] = '\0';
		(*lst)->content = ft_strjoin(ft_strdup((*lst)->content), buf);
		(*lst)->content_size = (*lst)->content_size + BUFF_SIZE;
		(*lst)->content[(*lst)->content_size] = '\0';
	}
}

int		fd_match(int fd, t_list **lst, char **line)
{
	t_list *curr;
	char **tab;

	curr = *lst;
	while (curr->next)
	{
		curr = curr->next;
		if (curr->fd == fd)
		{
			tab = ft_strsplit(curr->content, '\n');
			*line = tab[curr->line_number];
			curr->line_number += 1;
			return (1);
		}
	}
	return (0);
}				

int		get_next_line(int const fd, char **line)
{
	static t_list *lst = NULL;
	t_list *head;
	char **tab;

	if (!&(lst->content))
	{
		if (!(lst = (t_list *)malloc(sizeof(t_list))))
			return 0;
		ft_fill(fd, &lst);
		lst->next = NULL;
	}
	else
	{
		if (lst->fd != fd)
		{
			if (fd_match(fd, &lst, line))
				return (1);
			ft_push_new(&lst);
			ft_fill(fd, &lst);
		}
	}
	tab = ft_strsplit(lst->content, '\n');
	*line = tab[lst->line_number];
	lst->line_number += 1;

	return (1);
}

int main (int ac, char **av)
{
	int fd1;
	int fd2;
	int fd3;
	char *output;

	if (ac >= 2)
	{
		fd1 = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);
		fd3 = open(av[3], O_RDONLY);
		get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		get_next_line(fd2, &output);
		printf("fd2 %s\n", output);
		get_next_line(fd3, &output);
		printf("fd3 %s\n", output);
		get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		get_next_line(fd2, &output);
		printf("fd2 %s\n", output);
		get_next_line(fd3, &output);
		printf("fd3 %s\n", output);
		get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		get_next_line(fd2, &output);
		printf("fd2 %s\n", output);
		get_next_line(fd3, &output);
		printf("fd3 %s\n", output);
		get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		get_next_line(fd3, &output);
		printf("fd3 %s\n", output);
		get_next_line(fd1, &output);
		printf("fd3 %s\n", output);
		get_next_line(fd1, &output);
		printf("fd3 %s\n", output);
		get_next_line(fd1, &output);
		printf("fd3 %s\n", output);
		get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		close(fd1);
		close(fd2);
		close(fd3);
	}
	return (0);
}

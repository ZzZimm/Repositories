#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

// ATTENTION A BIEN CLEAN LE FT_STRSPLIT AVANT DE L'ENVOYER !!!

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
	char buf[BUFF_SIZE + 1];
	char *tmp;
	int rd;

	(*lst)->content = ft_strnew(BUFF_SIZE + 1);
	(*lst)->content_size = 0;
	(*lst)->line_number = 0;
	(*lst)->fd = fd;
	while((rd = read(fd,buf,BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		tmp = ft_strjoin((*lst)->content, buf);
		free ((*lst)->content);
		(*lst)->content = tmp;
		(*lst)->content_size = (*lst)->content_size + rd;
		(*lst)->content[(*lst)->content_size + rd] = '\0';
	}
	(*lst)->content_tab = ft_strsplit((*lst)->content, '\n');
	(*lst)->n_lines = count_words_c((*lst)->content,'\n');
}

int		fd_match(int fd, t_list **lst, char **line)
{
	t_list *curr;
	size_t i;

	i = -1;
	curr = *lst;
	while (curr->next)
	{
		curr = curr->next;
		if (curr->fd == fd)
		{
			if (curr->line_number >= curr->n_lines)
			{
				curr->line_number += 1;
				return (0);
			}
				*line = curr->content_tab[curr->line_number];
			curr->line_number += 1;
			return (1);
		}
	}
	return (0);
}				

int		get_next_line(int const fd, char **line)
{
	static t_list *lst = NULL;

	if (!line || fd < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	if (read(fd, NULL, 0) == 0)
		return (0);
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
	if (lst->line_number >= lst->n_lines)
	{
		lst->line_number += 1;
		return (0);
	}
	if (lst->content_tab[lst->line_number] == NULL)
	{
		*line = NULL;
		lst->line_number += 1;
		return (0);
	}
	*line = lst->content_tab[lst->line_number];
	lst->line_number += 1;

	return (1);
}


int main (int ac, char **av)
{
	int fd1;
	int fd2;
	int fd3;
	char *output;
	int rd;

	if (ac >= 2)
	{
		fd1 = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);
		fd3 = open(av[3], O_RDONLY);
		rd = get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		printf("ret = %d\n", rd);
		rd = get_next_line(fd2, &output);
		printf("fd2 %s\n", output);
		printf("ret = %d\n", rd);
		rd = get_next_line(fd3, &output);
		printf("fd3 %s\n", output);
		printf("ret = %d\n", rd);
		rd = get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		printf("ret = %d\n", rd);
		rd = get_next_line(fd2, &output);
		printf("fd2 %s\n", output);
		printf("ret = %d\n", rd);
		rd = get_next_line(fd3, &output);
		printf("fd3 %s\n", output);
		printf("ret = %d\n", rd);
		rd = get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		printf("ret = %d\n", rd);
		rd = get_next_line(fd2, &output);
		printf("fd2 %s\n", output);
		printf("ret = %d\n", rd);
		rd = get_next_line(fd3, &output);
		printf("fd3 %s\n", output);
		printf("ret = %d\n", rd);
		rd = get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		printf("ret = %d\n", rd);
		rd = get_next_line(fd2, &output);
		printf("fd2 %s\n", output);
		printf("ret = %d\n", rd);
		rd = get_next_line(fd3, &output);
		printf("fd3 %s\n", output);
		printf("ret = %d\n", rd);
		rd = get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		printf("ret = %d\n", rd);
		rd = get_next_line(fd2, &output);
		printf("fd2 %s\n", output);
		printf("ret = %d\n", rd);
		rd = get_next_line(fd3, &output);
		printf("fd3 %s\n", output);
		printf("ret = %d\n", rd);
		close(fd1);
		close(fd2);
		close(fd3);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:57:13 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/04 16:21:36 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char *ft_strtrimc(char *s, int c)
{
	int i;

	i = 0;
	if (c == '\0')
		return (s);
	while (s[i])
	{
		if (s[i] == c)
		{
			s[i] = '\0';
			return(s);
		}
		i++;
	}
	return (s);
}

static void return_line(int pos, t_list **lst, char **line)
{
	char *tmp;

//	printf("in lst_read : found \'\\n\' at pos %d \n", pos);
	*line = ft_strtrimc(ft_strdup((*lst)->content), '\n'); 
	tmp = ft_strsub((*lst)->content, pos + 1, (*lst)->content_size - (pos + 1));
	free((*lst)->content);
	(*lst)->content = tmp; 
	(*lst)->content_size = (*lst)->content_size - (pos + 1);
//	printf("lst->content = %s, lst->content_size = %lu \n", (*lst)->content, (*lst)->content_size);
}

static void	ft_lstread(int fd, t_list **lst, char **line)
{
	char buf[BUFF_SIZE + 1];
	char *tmp;
	char *res;
	int rd;

	
//	printf("__________________ lst_read_______________\n");
	while((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		tmp = ft_strjoin(((*lst)->content ? (*lst)->content : ""), buf);
		free((*lst)->content);
		(*lst)->content = tmp;
		(*lst)->content_size = (*lst)->content_size + rd;
		(*lst)->content[(*lst)->content_size] = '\0';
//		printf("end of first step of read, content = %s\n", (*lst)->content);
		if ((res = ft_strchr((*lst)->content, '\n')))
		{
			return_line(res - (*lst)->content, lst, line);
			return ;
		} 
	}
	if ((res = ft_strchr((*lst)->content, '\n')))
	{
		return_line(res - (*lst)->content, lst, line);
		return ;
	}
//	printf("\n_______________LOOOOOK ME HERE______________\n");
//	printf("lst->content = %s\n", (*lst)->content);
/*	if (*(*lst)->content)
	{
		*line = ft_strdup((*lst)->content);
		free((*lst)->content);
		(*lst)->content = NULL;
		return ;
	}*/
//	printf("Look at me now, content = [%s]\n", (*lst)->content);
//	printf("Look at me now, content = [%zu]\n", (*lst)->content_size);
	if ((*lst)->content_size)
	{
		*line = (*lst)->content;
	//	printf("LINE IN IF = %s\n", *line);
		(*lst)->content_size = 0;
		return ;
	}
	*line = NULL;
}
		
static void ft_push_new_lst(int fd, t_list **lst) 
{ 
    t_list	*new_node; 

	if (!(new_node = (t_list *)malloc(sizeof(t_list))))
		return ;
	new_node->content = NULL;
	new_node->content_size = 0;
	new_node->next = NULL;
	new_node->fd = fd;
	if ((*lst))
		new_node->next = (*lst);
	(*lst) = new_node;
}

int		get_next_line(int fd, char **line)
{
	static t_list *lst;
	t_list *curr;

//	printf("fd = %d\n", fd);
	if (!line || fd < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	if(!&(lst->content))
	{
		ft_push_new_lst(fd, &lst);
//	printf("__________________ lst_init ______________\n");
		ft_lstread(fd, &lst, line);
//	printf("FIRST LINE = %s\n", *line);
		return (*line ? 1 : 0);
	}
	if (lst->fd != fd)
	{
		curr = lst->next;
//		printf("\n\nCURR NEXT \n\n");
		while (curr)
		{
			if (curr->fd == fd)
			{
				ft_lstread(fd, &curr, line);
//		printf("LINE = %s\n", *line);
		return (*line ? 1 : 0);
			}
			curr = curr->next;
		}
		ft_push_new_lst(fd, &lst);
		ft_lstread(fd, &lst, line);
//		printf("LINE = %s\n", *line);
		return (*line ? 1 : 0);
	}
	ft_lstread(fd, &lst, line);
//	printf("LINE = %s\n", *line);
	return (*line ? 1 : 0);
}

int main (int ac, char **av)
{
	int fd;
	int fd1;
	int fd2;
	int fd3;
	char *output;
	int rd;

	if (ac == 1)
		return (1);
	fd = open(av[1], O_RDONLY);
//	fd2 = open(av[2], O_RDONLY);
	output = NULL;
/*	while (get_next_line(fd, &output) == 1)
	{
		printf("line : [%s]\n", output);
		free(output);
	}
	close(fd);*/
	if (ac >= 2)
	{
		fd1 = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);
		fd3 = open(av[3], O_RDONLY);
	while (get_next_line(fd1, &output) == 1) 
	{
		printf("line : [%s]\n", output);
		free(output);
		while (get_next_line(fd2, &output) == 1)
		{
		printf("line : [%s]\n", output);
		free(output);
			while(get_next_line(fd3, &output) == 1)
			{
			printf("line : [%s]\n", output);
			free(output);
			}
		}
	}
	
/*		rd = get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		free(output);
		rd = get_next_line(fd2, &output);
		printf("fd2 %s\n", output);
		free(output);
		rd = get_next_line(fd2, &output);
		printf("fd2 %s\n", output);
		free(output);
		rd = get_next_line(fd2, &output);
		printf("fd2 %s\n", output);
		free(output);
		rd = get_next_line(fd2, &output);
		printf("fd2 %s\n", output);
		free(output);
		rd = get_next_line(fd3, &output);
		printf("fd3 %s\n", output);
		free(output);
		rd = get_next_line(fd3, &output);
		printf("fd3 %s\n", output);
		free(output);
		rd = get_next_line(fd3, &output);
		printf("fd3 %s\n", output);
		free(output);
		rd = get_next_line(fd2, &output);
		printf("fd2 %s\n", output);
		free(output);
		rd = get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		free(output);
		rd = get_next_line(fd2, &output);
		printf("fd2 %s\n", output);
		free(output);
		rd = get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		free(output);
		rd = get_next_line(fd1, &output);
		printf("fd1 %s\n", output);
		free(output);
		rd = get_next_line(fd3, &output);
		printf("fd1 %s\n", output);
		free(output);
		printf("FIRST LEAK CHECK \n");
		rd = get_next_line(fd1, &output);
		free(output);
		printf("SECOND LEAK CHECK \n");
		rd = get_next_line(fd1, &output);
		free(output);
		rd = get_next_line(fd2, &output);
		free(output);
		rd = get_next_line(fd3, &output);
		free(output);
		rd = get_next_line(fd1, &output);
		free(output);
		rd = get_next_line(fd2, &output);
		free(output);
		rd = get_next_line(fd3, &output);
		free(output);
		rd = get_next_line(fd1, &output);
		free(output);
		rd = get_next_line(fd2, &output);
		free(output);
		rd = get_next_line(fd3, &output);
		free(output);
		rd = get_next_line(fd1, &output);
		free(output);
		rd = get_next_line(fd2, &output);
		free(output);
		rd = get_next_line(fd3, &output);
		free(output);
		while ((rd = get_next_line(fd1, &output)))
		{
			if (rd <= 0)
				break ;
			printf("%s\n", output);
		}
		rd = get_next_line(fd2, &output);
*/
/*		rd = get_next_line(fd1, &output);
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
		printf("ret = %d\n", rd);*/
		close(fd1);
		close(fd2);
		close(fd3);
	}
	return (0);
}

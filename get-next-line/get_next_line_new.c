/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:57:13 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/02 20:05:42 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_next_line(int fd, char **line)
{
	static t_list *lst;
	int rd;
	
	if (!line || !fd || read(fd, NULL, 0) == -1)
		return (-1);
	if(!&(lst->content))
	{
		lst = ft_lstinit(fd);

	if (lst->fd != fd)
	{

	}
}

static t_list	*ft_lstinit(int fd)
{
	t_list *lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (0);
	lst->content = NULL;
	lst->line_number = 0;
	lst->content_size = 0;
	lst->fd = fd;
	return(lst);
}

static unsigned int	ft_strposchr(char const *s, int c)
{
	int i;

	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char *ft_strtrimc(char *s, int c)
{
	int i;

	if (c == '\0')
		return (s);
	while (s[i])
	{
		if (s[i] == c)
			s[i + 1] = '\0';
		i++;
	}
	return (s);
}


static char	*ft_lstread(t_list **lst, char **line)
{
	char buf[BUFF_SIZE + 1];
	char *tmp;
	int rd;
	int pos;

	
	while((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		tmp = ft_strjoin((*lst)->content, buf)
		free((*lst)->content);
		(*lst)->content = tmp
		(*lst)->content_size += rd;
		(*lst)->content[(*lst)->content_size] = '\0';
			if ((pos = ft_strposchr((*lst)->content, '\n')) > 0)
			{
				*line = ft_strtrimc(ft_strdup((*lst)->content), '\n'); //ca malloc un peu trop...
				tmp = ft_strsub((*lst)->content, pos, (*lst)->content_size - pos);
				free((*lst)->content);
				(*lst)->content = tmp; 
				(*lst)->content_size = (*lst)->content_size - pos;
				return;
			}
	}
	*line = (*lst)->content;
}
		



				ft_strchr(buf, '\n') != NULL
	}
	(*lst)->content = ft_strnew(BUFF_SIZE + 1);
	(*lst)->


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:43:08 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 11:45:20 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int		fd;
	char	c;

	if (ac == 1)
		write(2, "File name missing.\n", 19);
	if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
		while (read(fd, &c, 1))
			write(1, &c, 1);
		close(fd);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:01:23 by exam              #+#    #+#             */
/*   Updated: 2019/04/25 16:42:59 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 21
#include "fillit.h"
#include "libft.h"
#include "parser.h"
#include "solver.h"
#include "utils.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

t_tetris	*exit_read(void *ptr)
{
	free(ptr);
	return (NULL);
}

t_tetris	*read_file(int fd)
{
	int			piece_index;
	int			nb_read;
	char		buf[BUF_SIZE + 1];
	t_tetris	*pieces;

	piece_index = 0;
	if (!(pieces = (t_tetris *)malloc(27 * sizeof(t_tetris))))
		return (NULL);
	while ((nb_read = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (piece_index > 25)
			return (exit_read(pieces));
		buf[nb_read] = '\0';
		if (lines_ok(buf, nb_read) && piece_ok(buf))
			store_buf(buf, pieces + piece_index);
		else
			return (exit_read(pieces));
		pieces[piece_index].index = piece_index;
		piece_index++;
	}
	if (ft_strlen(buf) != 20)
		return (exit_read(pieces));
	pieces[piece_index].value.t64 = 0;
	return (pieces);
}

int			main(int argc, char *argv[])
{
	t_tetris	*pieces;
	int			nb_pieces;

	if (argc != 2 || !(pieces = read_file(open(argv[1], O_RDONLY))))
	{
		ft_putendl("error");
		return (1);
	}
	nb_pieces = 0;
	while (pieces[nb_pieces].value.t64)
		nb_pieces++;
	reverse_pieces_bytes(pieces);
	solve(pieces, nb_pieces);
}

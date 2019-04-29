/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 21:52:52 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/25 16:43:46 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include "utils.h"
#include <sys/types.h>

int		check_piece(u_int16_t *square, t_tetris piece)
{
	return (!(*(u_int64_t *)(square + piece.y) & (piece.value.t64 >> piece.x)));
}

void	toggle_piece(u_int16_t *square, t_tetris piece)
{
	*(u_int64_t *)(square + piece.y) ^= piece.value.t64 >> piece.x;
}

int		solve_size(u_int16_t *square, t_tetris *pieces, int size)
{
	if (pieces->value.t64 == 0)
		return (1);
	if (pieces->index > 0 && (pieces - 1)->value.t64 == pieces->value.t64)
	{
		pieces->x = pieces->x <= size - pieces->width ? (pieces - 1)->x + 1 : 0;
		pieces->y = pieces->x == 0 ? (pieces - 1)->y + 1 : (pieces - 1)->y;
	}
	while (pieces->y <= size - pieces->height)
	{
		while (pieces->x <= size - pieces->width)
		{
			if (check_piece(square, *pieces))
			{
				toggle_piece(square, *pieces);
				if (solve_size(square, pieces + 1, size))
					return (1);
				toggle_piece(square, *pieces);
			}
			++(pieces->x);
		}
		++(pieces->y);
		pieces->x = 0;
	}
	pieces->y = 0;
	return (0);
}

void	solve(t_tetris *pieces, int nb_pieces)
{
	u_int16_t	square[16];
	int			size;

	size = 0;
	ft_bzero(square, 16 * sizeof(u_int16_t));
	while (size * size < 4 * nb_pieces)
		++size;
	while (!solve_size(square, pieces, size) && size <= 16)
	{
		++size;
		ft_bzero(square, 16 * sizeof(u_int16_t));
	}
	if (size != 17)
	{
		print_sol(pieces, size);
	}
	else
		ft_putendl("error");
}

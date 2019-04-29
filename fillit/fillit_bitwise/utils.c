/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 22:51:28 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/25 16:51:10 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "fillit.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/types.h>

void	set_bit(u_int64_t *nb, int bit_pos)
{
	*nb |= BIT >> bit_pos;
}

void	copy_t16_to_str(u_int16_t nb, char *str, char c)
{
	u_int16_t	bit;
	int			i;

	bit = 32768;
	i = 0;
	while (str[i])
	{
		if (bit & nb)
			str[i] = c;
		i++;
		bit >>= 1;
	}
}

void	reverse_pieces_bytes(t_tetris *pieces)
{
	u_int16_t tmp;

	while (pieces->value.t64)
	{
		tmp = pieces->value.t16.p0;
		pieces->value.t16.p0 = pieces->value.t16.p3;
		pieces->value.t16.p3 = tmp;
		tmp = pieces->value.t16.p1;
		pieces->value.t16.p1 = pieces->value.t16.p2;
		pieces->value.t16.p2 = tmp;
		pieces++;
	}
}

void	print_sol(t_tetris *pieces, int size)
{
	char	c;
	char	tab[16][17];
	int		i;

	c = 'A';
	i = -1;
	while (++i < size)
	{
		ft_memset(tab[i], '.', size);
		tab[i][size] = '\0';
	}
	while (i < 16)
		tab[i++][0] = '\0';
	i = -1;
	while (pieces[++i].value.t64)
	{
		pieces[i].value.t64 >>= pieces[i].x;
		copy_t16_to_str(pieces[i].value.t16.p3, tab[pieces[i].y], c);
		copy_t16_to_str(pieces[i].value.t16.p2, tab[1 + pieces[i].y], c);
		copy_t16_to_str(pieces[i].value.t16.p1, tab[2 + pieces[i].y], c);
		copy_t16_to_str(pieces[i].value.t16.p0, tab[3 + pieces[i].y], c++);
	}
	i = -1;
	while (++i < size)
		ft_putendl(tab[i]);
}

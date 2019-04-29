/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:18:16 by exam              #+#    #+#             */
/*   Updated: 2019/04/25 17:23:15 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include "utils.h"
#include "utils2.h"

int		get_line_len(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '.' && str[i] != '#')
			return (-1);
		++i;
	}
	return (i);
}

int		lines_ok(char *str, int nb_read)
{
	int i;
	int nb_lines;
	int line_len;

	i = 0;
	nb_lines = 0;
	while (str[i])
	{
		++nb_lines;
		line_len = get_line_len(str + i);
		if (line_len != 4)
		{
			if (nb_read == 21 && nb_lines == 5 && line_len == 0)
				return (1);
			return (0);
		}
		i += 5;
	}
	if (str[i - 1] != '\n')
		return (0);
	return (nb_lines == 4);
}

int		piece_ok(char *buf)
{
	int i;
	int connections;
	int block_count;

	i = 0;
	connections = 0;
	block_count = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			block_count++;
			connections += (i > 0 && buf[i - 1] == '#')
				+ (i > 4 && buf[i - 5] == '#')
				+ (i < 18 && buf[i + 1] == '#')
				+ (i < 14 && buf[i + 5] == '#');
		}
		++i;
	}
	return ((block_count == 4) && (connections == 6 || connections == 8));
}

void	get_info(t_tetris *pieces)
{
	int bit_pos;

	bit_pos = 0;
	pieces->width = 0;
	pieces->height = 0;
	while (bit_pos <= 51)
	{
		if (val(pieces->value.t64, bit_pos) == 1)
		{
			if (bit_pos % 16 > pieces->width)
				pieces->width = bit_pos % 16;
			if (bit_pos / 16 > pieces->height)
				pieces->height = bit_pos / 16;
		}
		if (bit_pos % 16 == 3)
			bit_pos += 16 - (bit_pos % 16) - 1;
		++bit_pos;
	}
	++(pieces->width);
	++(pieces->height);
	pieces->x = 0;
	pieces->y = 0;
}

void	store_buf(char *buf, t_tetris *pieces)
{
	unsigned long long	piece;
	int					bit_pos;
	int					offset;

	piece = 0;
	offset = get_offset(&buf);
	bit_pos = 0;
	while (*buf)
	{
		if (*buf == '#')
			set_bit(&piece, bit_pos);
		else if (*buf == '\n')
			bit_pos += 16 - (bit_pos % 16) - 1 - offset;
		++buf;
		++bit_pos;
	}
	pieces->value.t64 = piece;
	get_info(pieces);
}

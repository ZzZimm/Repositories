/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:22:33 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/24 18:31:51 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include <sys/types.h>

int		min(int a, int b)
{
	return (a < b ? a : b);
}

int		get_next_offset(char *buf)
{
	char	*line_start;
	char	*first_block;
	int		offset;

	line_start = ft_strchr(buf, '\n') + 1;
	if (!(first_block = ft_strchr(line_start, '#')))
		return (5);
	offset = first_block - line_start;
	line_start = ft_strchr(first_block, '\n') + 1;
	if (!(first_block = ft_strchr(line_start, '#')))
		return (offset);
	return (min((first_block - line_start), offset));
}

int		get_offset(char **buf)
{
	int offset;
	int next_offset;

	offset = 0;
	while (**buf != '#')
	{
		offset++;
		(*buf)++;
		if (**buf == '\n')
			offset = -1;
	}
	if ((next_offset = get_next_offset(*buf)) < offset)
	{
		*buf -= offset - next_offset;
		offset = next_offset;
	}
	return (offset);
}

int		val(u_int64_t nb, int bit_pos)
{
	return ((nb & (BIT >> bit_pos)) != 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:37:38 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/05 09:27:59 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i[3];

	i[0] = -1;
	i[1] = 0;
	i[2] = ft_strlen(dst);
	if (size >= i[2])
	{
		while (src[++i[0]] && i[1]++ < size - i[2] - 1)
			dst[i[0] + i[2]] = src[i[0]];
		dst[i[0] + i[2]] = '\0';
		return (i[2] + ft_strlen((char *)src));
	}
	return (size + ft_strlen((char *)src));
}

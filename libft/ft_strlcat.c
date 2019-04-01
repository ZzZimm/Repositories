/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:37:38 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 14:37:40 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t dstsize)
{
	size_t i[3];
	
	i[0] = -1;
	i[1] = 0;
	i[2] = ft_strlen(s1);
	if (dstsize >= i[2])
	{
		while (s2[++i[0]] && i[1]++ < dstsize - i[2] - 1)
			s1[i[0] + i[2]] = s2[i[0]];
		s1[i[0] + i[2]] = '\0';
		return (i[2] + ft_strlen((char *)s2));
	}
	return (dstsize + ft_strlen((char *)s2));
}

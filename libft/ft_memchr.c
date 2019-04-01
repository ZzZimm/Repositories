/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:12:02 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 14:13:02 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const char *s, int c, size_t n)
{
	while (n--)
	{
		if (*((unsigned char *)s) != (unsigned char)c)
			s++;
		else
			return ((void *)s);
	}
	return (NULL);
}

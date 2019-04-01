/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:16:02 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 14:16:04 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (src <= dst)
		while (n--)
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	else
		ft_memcpy(dst, src, n);
	return (dst);
}

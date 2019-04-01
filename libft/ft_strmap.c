/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:38:50 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 14:39:07 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *new;
	size_t len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	if(!(new = ft_strnew(len)))
		return (NULL);
	while (*s)
		*new++ = f(*s++);
	return (new - len);
}

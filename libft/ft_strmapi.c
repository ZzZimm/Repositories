/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:39:13 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 14:39:24 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *new;
	size_t len;
	size_t i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	if (!(new = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (s[++i])
		new[i] = f(i,s[i]);
	return (new);
}
	

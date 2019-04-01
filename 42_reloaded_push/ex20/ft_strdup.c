/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:34:21 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 12:35:39 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = -1;
	if (!(dest = (char *)malloc(sizeof(*dest) * (ft_strlen(src) + 1))))
		return ((void*)0);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

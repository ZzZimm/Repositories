/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:33:49 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 14:34:09 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = -1;
	if (!(dest = (char *)malloc(sizeof(*dest) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return(dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:37:01 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 14:37:16 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *sub;

	if (!s1 || !s2)
		return (NULL);
	if (!(sub = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2))))
		return (NULL);
	sub = ft_strcat(sub, s1);
	sub = ft_strcat(sub, s2);
	return (sub);
}

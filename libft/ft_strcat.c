/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:21:55 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 14:29:56 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int i[2];

	i[0] = -1;
	i[1] = ft_strlen(s1);
	while (s2[++i[0]])
		s1[i[0] + i[1]] = s2[i[0]];
	s1[i[0] + i[1]] = '\0';
	return (s1);
}

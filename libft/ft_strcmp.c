/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:32:19 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 14:32:36 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1++ != *s2++)
			return (*((unsigned char *)(--s1)) - *((unsigned char *)(--s2)));
	}
	return (*((unsigned char *)s1) - *((unsigned char *)s2));
}

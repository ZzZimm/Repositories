/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:07:18 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/05 09:29:00 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int i[2];

	i[0] = 0;
	while (*haystack && i[0]++ <= len)
	{
		i[1] = 0;
		while (needle[i[1]] && needle[i[1]] == haystack[i[1]])
			i[1]++;
		if (needle[i[1]] == '\0' && i[1] + i[0] - 1 <= len)
			return ((char *)haystack);
		haystack++;
	}
	return (*needle == '\0' ? (char *)haystack : NULL);
}

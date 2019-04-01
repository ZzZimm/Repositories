/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:37:03 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 12:36:14 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*range;
	int	len;

	len = max - min;
	if (!(range = (int *)malloc(sizeof(*range) * len)))
		return ((void *)0);
	while (min < max)
		*range++ = min++;
	return (range - len + 1);
}

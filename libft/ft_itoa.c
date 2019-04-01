/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:02:16 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 14:03:14 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_intlen(long n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char *str;
	long i[2];

	i[0] = 0;
	i[1] = n;
	if (!(str = (char *)malloc(sizeof(char) * (ft_intlen(n) + 1))))
		return (NULL);
	if (n < 0)
	{
		*str++ = '-';
		i[1] = -i[1];
	}
	while (i[0] < ft_intlen(i[1]))
		*str++ = '0' + i[1] / ft_pow(10, ft_intlen(i[1]) - ++i[0]) % 10;
	*str = '\0';
	return (str - ft_intlen(n));
}

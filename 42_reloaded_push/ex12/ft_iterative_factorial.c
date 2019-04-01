/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:26:45 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 11:27:15 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int res;

	res = 1;
	if (nb <= 0)
		return (nb < 0 ? 0 : 1);
	while (nb >= 1)
		res = res * nb--;
	return (res);
}

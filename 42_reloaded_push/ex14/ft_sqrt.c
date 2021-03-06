/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:28:22 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 11:28:53 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int root;

	root = 0;
	while (root <= nb / 2 + 1)
	{
		if (root * root == nb)
			return (root);
		root++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:31:04 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 12:33:30 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str++);
	}
}

int		main(int ac, char **av)
{
	if (ac > 0)
	{
		while (*(av + 1))
		{
			ft_putstr(*(av++ + 1));
			ft_putchar('\n');
		}
	}
	return (0);
}

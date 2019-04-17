/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:30:49 by lzimmerm          #+#    #+#             */
/*   Updated: 2018/08/13 13:23:16 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

long	ft_pow(int nb, int p)
{
	if (p == 0)
		return (1);
	return (nb * ft_pow(nb, p - 1));
}

int		ft_base_check(char *base)
{
	int i;

	i = 1;
	if (ft_strlen(base) <= 1)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		while (base[i])
		{
			if (base[i] == *base)
				return (0);
			i++;
		}
		base++;
		i = 1;
	}
	return (1);
}

void	ft_putnbr_base_long(long nbr, char *base)
{
	int max_p;
	int base_len;
	int index;

	max_p = 0;
	base_len = ft_strlen(base);
	index = 0;
	ft_putchar('-');
	while (ft_pow(base_len, max_p) <= nbr)
		max_p++;
	while (max_p-- > 0)
	{
		index = (nbr / ft_pow(base_len, max_p)) % base_len;
		ft_putchar(base[index]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int max_p;
	int base_len;
	int index;

	max_p = 0;
	base_len = ft_strlen(base);
	index = 0;
	if (!ft_base_check(base))
		return ;
	if (nbr == 0)
		ft_putchar(base[0]);
	if (nbr == -2147483648)
		ft_putnbr_base_long(2147483648, base);
	if (nbr < 0 && nbr != -2147483648)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	while (ft_pow(base_len, max_p) <= nbr)
		max_p++;
	while (max_p-- > 0)
	{
		index = (nbr / ft_pow(base_len, max_p)) % base_len;
		ft_putchar(base[index]);
	}
}

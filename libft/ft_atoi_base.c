/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_str_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:42:39 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/17 10:25:51 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_len(char const *str)
{
	int i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
		if (*str == '-' || *str == '+')
			return (i);
	}
	return (i);
}

int		ft_pow(int nb, int p)
{
	if (p == 0)
		return (1);
	return (nb * ft_pow(nb, p - 1));
}

int		ft_base_check(char const *base)
{
	int i;

	i = 1;
	if (ft_len(base) <= 1)
		return (0);
	while (*base++)
	{
		if (*base == '+' || *base == '-')
			return (0);
		while (base[i])
		{
			if (base[i] == *base)
				return (0);
			i++;
		}
		i = 1;
	}
	return (1);
}

int		ft_str_check(char const *str, char const *base)
{
	int i;
	int j;
	int c;

	c = 0;
	i = 0;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		j = 0;
		c = 0;
		while (base[j])
		{
			if (*str == base[j] || *str == '+' || *str == '-')
				c++;
			j++;
		}
		if (c == 0)
			return (0);
		str++;
	}
	return (1);
}

int		ft_atoi_base(char const *str, char const *base)
{
	int i;
	int j;
	int res;
	int sign;

	i = -1;
	res = 0;
	sign = 1;
	if (!ft_str_check(str, base) || !ft_base_check(base))
		return (0);
	if (str[0] == '-')
		sign = -1;
	while (str[++i])
	{
		j = 0;
		while (j++ < ft_len(base) && i < ft_len(str))
		{
			if (str[i] == base[j])
			{
				res = res + j * ft_pow(ft_len(base), ft_len(str) - 1 - i++);
				j = 0;
			}
		}
	}
	return (sign * res);
}

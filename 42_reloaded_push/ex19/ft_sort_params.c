/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:31:53 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 12:34:48 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*s1 && *s2 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_sort_string_table(char **tab, int size)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac > 1)
	{
		ft_sort_string_table(av + 1, ac - 1);
		while (i < ac)
		{
			ft_putstr(av[i++]);
			ft_putchar('\n');
		}
	}
	return (0);
}

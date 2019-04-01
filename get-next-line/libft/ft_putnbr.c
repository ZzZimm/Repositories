#include "libft.h"

void	ft_putnbr(int n)
{
	long i[2];

	i[0] = 0;
	i[1] = n;
	if (n < 0)
	{
		i[1] = -i[1];
		ft_putchar ('-');
	}
	while (ft_pow(10,(i[0] + 1)) <= i[1])
		i[0]++;
	while (i[0] >= 0)
		ft_putchar ('0' + i[1]  / ft_pow(10,i[0]--) % 10);
}

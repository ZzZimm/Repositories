#include "libft.h"

long	ft_pow(int nb, int p)
{
	if (p == 0)
		return (1);
	return (nb * ft_pow(nb, p - 1));
}

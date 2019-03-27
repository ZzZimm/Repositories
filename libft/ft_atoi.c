#include "libft.h"

int		ft_atoi(const char *str)
{
	int res;
	int neg;

	res = 0;
	neg = 1;
	while ((*str >= 9 && *str <= 17) || *str == ' ' || *str == '-'
		|| *str == '+')
	{
		str++;
		if ((*(str-1) == '-' && (neg = -1)) || *(str - 1) == '+')
			break;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (neg * res);
}

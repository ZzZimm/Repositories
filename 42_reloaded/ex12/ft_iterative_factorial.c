int ft_iterative_factorial(int nb)
{
	int res;

	res = 1;
	if (nb <= 0)
		return(nb < 0 ? 0 : 1);
	while (nb >= 1)
		res = res * nb--;
	return (res);
}

int main()
{
	printf("%d",ft_iterative_factorial(-1));
	return (0);
}

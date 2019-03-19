void ft_ft(int *nbr)
{
	*nbr = 42;
}

int main ()
{
	int a;

	a = 2;
	ft_ft(&a);
	printf("%d", a);
	return(0);
}

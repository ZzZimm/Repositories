void ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int main ()
{
	int mod;
	int div;

	ft_div_mod(4,2,&div, &mod);
	printf("%d, %d",div,mod);
return(0);
}

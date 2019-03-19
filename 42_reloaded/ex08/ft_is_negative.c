void ft_putchar(char c)
{
	write(1,&c,1);
}

void ft_is_negative(int n)
{
	n < 0 ? ft_putchar('N') : ft_putchar('P');
}

int main()
{
	ft_is_negative(4);
}

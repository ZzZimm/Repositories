int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int main()
{
	printf("%d",ft_strlen("omglol"));
	return(0);
}

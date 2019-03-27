int *ft_range(int min, int max)
{
	int *range;
	int len;

	len = max - min;
	if (!(range = (int *)malloc(sizeof(*range) * len)))
		return ((void *)0);
	
	while (min < max)
		*range++ = min++;
	return (range - len + 1);
}

int main()
{
	int *tab;
	int i;

	tab = ft_range(2,10);
	i = 0;
	while(i < 7)
	{
		printf("%d\n",*tab);
		tab++;
		i++;
	}
	return (0);
}

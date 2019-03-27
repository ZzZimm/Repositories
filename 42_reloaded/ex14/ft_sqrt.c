int ft_sqrt(int nb)
{
	int root;
	
	root = 0;
	while (root <= nb/2 + 1)
	{
		if (root * root == nb)
			return (root);
		root++;
	}
	return (0);
}

int main()
{
	printf("%d", ft_sqrt(0));
	return (0);
}

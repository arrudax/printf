char	*ft_long_to_hex(void *ptr)
{
	int				i;
	char			hex[20];
	unsigned long	address;
	int				remainder;
	int				padding;

	i = 0;
	address = (unsigned long)ptr;
	if (adress == 0)
	{
		while (i <= 2)
		{
			if (i == 1)
				hex[i] = 'x';
			else
				hex[i] = '0';
			i++;
		}
		hex[i] = '\0';
		return (hex);
	}

	while (address > 0)
	{
		ramainder = address % 16;
		if (ramainder < 10)
			hex[i] = '0' + remainder;
		else
			hex[i] = 'a' + (remainder - 10);
		address /= 16;
		i++
	}

	padding = 16 - i;
}

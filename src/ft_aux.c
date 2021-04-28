int	ft_str_is_numeric(char *str)
{
	unsigned int	i;
	int				result;

	result = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = 1;
		else
		{
			result = 0;
			return (result);
		}
		i++;
	}
	return (result);
}

int	ft_atoi_b(char *str)
{
	int		result;
	int		sign;
	char	*charptr;

	result = 0;
	sign = 1;
	charptr = str;
	while (*charptr >= '0' && *charptr <= '9')
	{
		result *= 10;
		result += (int)(*charptr - '0');
		charptr++;
	}
	return (result * sign);
}

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
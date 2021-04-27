int	ft_check_first_line(char *str)
{
	int		res;
	int		count;
	int		i;

	i = 0;
	count = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i < 1)
		return (0);
	while (str[i] >= 32 && str[i] < 127)
	{
		count++;
		i++;
	}
	if (str[i] == str[i - 1] || str[i] == str[i - 2]
		|| str[i - 1] == str[i - 2] || count != 3 || str[i] != 0)
		return (0);
	else
		return (1);
}

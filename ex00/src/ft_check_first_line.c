#include "ft_str.h"
#include <stdio.h>

int	ft_check_first_line(char *str)
{
	int	i;

	i = -1;
	if ((ft_strlen(str) < 4)
		|| str[ft_strlen(str) - 1] == str[ft_strlen(str) - 2]
		|| str[ft_strlen(str) - 2] == str[ft_strlen(str) - 3]
		|| str[ft_strlen(str) - 3] == str[ft_strlen(str) - 1])
		return (0);
	while (++i < ft_strlen(str))
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		if (i < ft_strlen(str) - 3 && (str[i] < '0' || str[i] > '9'))
			return (0);
	}
	return (1);
}

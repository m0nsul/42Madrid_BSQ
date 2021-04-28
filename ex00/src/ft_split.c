#include <stdlib.h>
#include "ft_str.h"
#include "ft_strxcpy.h"

int	is_in_charset(char *charset, char to_find)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (to_find == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_next_str(char **pos_in_str, char *charset, int *next_str_len)
{
	int		i;
	char	*str_start;

	*next_str_len = 0;
	str_start = 0;
	i = 0;
	while ((*pos_in_str)[i])
	{
		if (is_in_charset(charset, (*pos_in_str)[i]) && str_start != 0)
		{
			*pos_in_str = str_start + *next_str_len;
			return (str_start);
		}
		else if (!is_in_charset(charset, (*pos_in_str)[i]) && str_start == 0)
			str_start = &(*pos_in_str)[i];
		if (!is_in_charset(charset, (*pos_in_str)[i]))
			*next_str_len = *next_str_len + 1;
		i++;
	}
	*pos_in_str = str_start + *next_str_len;
	if (*next_str_len == 0)
		return (0);
	return (str_start);
}

char	**ft_build_tab(char *str, char *charset)
{
	int		nb_str;
	char	**strs;
	int		next_str_len;
	char	*pos_in_str;

	nb_str = 0;
	next_str_len = 0;
	pos_in_str = str;
	while (ft_get_next_str(&pos_in_str, charset, &next_str_len))
		nb_str++;
	strs = (char **)malloc(sizeof(char *) * (nb_str + 1));
	if (!(strs))
		return (0);
	return (strs);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		next_str_len;
	char	*next_str;
	char	*pos_in_str;
	int		i;

	strs = ft_build_tab(str, charset);
	if (!(strs))
		return (0);
	i = 0;
	pos_in_str = str;
	next_str = ft_get_next_str(&pos_in_str, charset, &next_str_len);
	while (next_str)
	{
		strs[i] = (char *)malloc(sizeof(char) * next_str_len + 1);
		if (!(strs[i]))
			return (0);
		ft_strncpy(strs[i], next_str, next_str_len);
		i++;
		next_str = ft_get_next_str(&pos_in_str, charset, &next_str_len);
	}
	strs[i] = 0;
	return (strs);
}

void	ft_split_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		free(tab[i++]);
	free(tab);
}

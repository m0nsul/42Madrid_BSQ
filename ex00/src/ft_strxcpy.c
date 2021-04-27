#include <stdlib.h>
#include <errno.h>
#include "ft_str.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int		index;

	index = 0;
	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*dst;
	int		i;

	len = ft_strlen(src);
	dst = (char *) malloc(len * sizeof(char));
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	if (dst == NULL)
		errno = ENOMEM;
	return (dst);
}

char	*ft_strndup(char *src, int pos, int size)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(*dest) * (size + 1));
	if (!(dest))
		return (0);
	while (i < size)
	{
		dest[i] = src[pos + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dst, const char *src)
{
	char	*ptr;

	ptr = dst + ft_strlen(dst);
	while (*src != '\0')
		*ptr++ = *src++;
	*ptr = '\0';
	return (dst);
}

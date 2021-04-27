#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_file.h"
#include "ft_split.h"

char	*ft_filetostr(char *path)
{
	int				file;
	unsigned int	nbchars;
	char			currchar;
	char			*filestr;
	int				i;

	file = ft_open_file(path);
	if (file < 0)
		return (NULL);
	nbchars = 0;
	while (read(file, &currchar, 1))
		nbchars++;
	filestr = malloc(sizeof(*filestr) * (nbchars + 1));
	if (!filestr)
		return (NULL);
	close(file);
	file = ft_open_file(path);
	i = 0;
	while (read(file, filestr + i, 1))
		i++;
	ft_close_file(file);
	filestr[nbchars] = '\0';
	return (filestr);
}

char	**ft_filegetlines(char *path)
{
	char	**lines;
	char	*filestr;

	filestr = ft_filetostr(path);
	if (!filestr)
		return (NULL);
	lines = ft_split(filestr, "\n");
	free(filestr);
	return (lines);
}

int	ft_printlines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i] != 0)
		i++;
	return (i);
}

int	ft_getlinesnum(char **lines)
{
	int	i;

	i = 0;
	while (lines[i] != 0)
	{
		i++;
	}
	return (i);
}

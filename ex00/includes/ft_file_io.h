#ifndef FT_FILE_IO_H
# define FT_FILE_IO_H

char	*ft_filetostr(char *path);
char	**ft_filegetlines(char *path);
int		ft_getlinesnum(char **lines);
int	ft_printlines(char **lines);

#endif

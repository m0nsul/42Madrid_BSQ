#ifndef FT_SPLIT_H
# define FT_SPLIT_H

int		ft_is_charset(char *src, int pos, char *charset);
int		ft_wrdlen(char *str, int pos, char *charset);
char	**ft_split(char *str, char *charset);
void	ft_split_free(char **tab);

#endif
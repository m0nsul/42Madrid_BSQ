#ifndef FT_BOARD_SQUARES_H
# define FT_BOARD_SQUARES_H

int		ft_sqcalcneigh(t_b *board, int i, int j);
void	ft_squarescalculate(t_b *board);
void	ft_squaresinit(t_b *board, char **lines);
void	ft_squaresfree(t_b *board);
void	ft_boardinitsolutions(t_b *board);

#endif
#ifndef FT_BOARD_H
# define FT_BOARD_H
# include "ft_enums.h"

typedef enum e_square_type
{
	fr = 1,
	obs = 0
}	t_square_type;

typedef struct s_board_square
{
	t_square_type	type;
	int				neighcalc;
	int				is_solution;

}	t_bsq;

typedef struct s_board
{
	char		path[100];
	int			x_size;
	int			y_size;
	int			density;
	char		free;
	char		obst;
	char		aqchar;
	char		solution_max;
	int			error;
	t_bsq		***squares;
}	t_b;

int		ft_boardcreate(t_b	*board, char *path);
int		ft_boardinit(t_b *board, char *path);
void	ft_boardfree(t_b *board);
int		ft_checkfile(char **lines, int lines_size);
int		ft_checkfile_chars (char **lines, int lines_size);

#endif

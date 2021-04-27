#ifndef		FT_BOARD_H
# define	FT_BOARD_H
# define	DEFAULT_BOARD "tablero452"
# include	"ft_enums.h"

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
	char		*path;
	int			x_size;
	int			y_size;
	int			density;
	char		free;
	char		obst;
	char		aqchar;
	char		solution_max;
	t_bsq		***squares;
}	t_b;

t_b		*ft_boardcreate(char *path);
void	ft_boardinit(t_b *board, char *path);
void	ft_boardfree(t_b *board);
int		ft_checkfile(char **lines, int lines_size);

#endif
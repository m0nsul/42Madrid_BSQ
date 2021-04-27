#include <stdlib.h>
#include <stdio.h>
#include "ft_board.h"
#include "ft_file_io.h"
#include "ft_str.h"
#include "ft_board_print.h"
#include "ft_board_squares.h"
#include "ft_split.h"
#include "ft_strxcpy.h"

void	ft_boardinit(t_b *board, char *path)
{
	char	**lines;
	int		lines_size;
	int		i;
	int		len_line0;

	lines = ft_filegetlines(path);
	lines_size = ft_getlinesnum(lines);
	len_line0 = ft_strlen(lines[0]);
	board->path = ft_strdup(path);
	board->x_size = ft_strlen(lines[1]);
	board->y_size = lines_size - 1;
	board->free = lines[0][len_line0 - 3];
	board->obst = lines[0][len_line0 - 2];
	board->aqchar = lines[0][len_line0 - 1];
	board->squares = (t_bsq ***)malloc(board->y_size * sizeof(t_bsq **));
	i = -1;
	while (++i < board->y_size)
		board->squares[i] = (t_bsq **)malloc(board->x_size * sizeof(t_bsq *));
	ft_squaresinit(board, lines);
	ft_split_free(lines);
	ft_squarescalculate(board);
	ft_boardinitsolutions(board);
	ft_boardprint(board);
	ft_boardprint_solutions(board);
}

t_b	*ft_boardcreate(char *path)
{
	t_b	*board;

	board = (t_b *) malloc (sizeof(t_b));
	if (!board)
		return (0); // TODO: pendiente crear enums para control de errores
	ft_boardinit(board, path);
	return (board);
}

void	ft_boardfree(t_b *board)
{
	ft_squaresfree(board);
	free(board->squares);
	free(board->path);
	free(board);
}

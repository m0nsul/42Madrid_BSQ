#include <stdlib.h>
#include <stdio.h>
#include "ft_board.h"
#include "ft_file_io.h"
#include "ft_str.h"
#include "ft_board_print.h"
#include "ft_board_squares.h"
#include "ft_split.h"
#include "ft_strxcpy.h"
#include "ft_aux.h"

void	ft_putmaperror(char *error)
{
	char	c;

	c = '\n';
	ft_putstr(error);
	ft_putchar(c);
	exit(1);
}

void	ft_checkfile_chars (char **lines, int lines_size)
{
	int	i;
	int	j;
	int	line_len;
	int	len_line0;

	len_line0 = ft_strlen(lines[0]);
	i = 0;
	line_len = ft_strlen(lines[1]);
	while (++i < lines_size)
	{
		j = -1;
		while(++j < line_len)
			if (lines[i][j] != lines[0][len_line0 - 3] &&
				lines[i][j] != lines[0][len_line0 - 2])
				ft_putmaperror("map error wrong char found");
	}
}
int	ft_checkfile(char **lines, int lines_size)
{
	int		i;
	int		line_width;
	int		len_line0;
	char	size_atoi[10];
	int		y_size;

	i = 0;
	if (!lines[0])
		ft_putmaperror("map error empty file");
	len_line0 = ft_strlen(lines[0]);
	if (lines_size < 2)
		ft_putmaperror("map error not enough lines");
	line_width = ft_strlen(lines[1]);
	y_size = ft_atoi_b(ft_strncpy(size_atoi, lines[0], len_line0 - 3));
	if (y_size != lines_size - 1)
		ft_putmaperror("map error lines number doesnt match");
	while (++i < lines_size)
	{
		if (ft_strlen(lines[i]) != line_width)
			ft_putmaperror("map error line width");
		else if (ft_strlen(lines[i]) < 1)
			ft_putmaperror("map error line lenght");
	}
	ft_checkfile_chars (lines, lines_size);
	return (1);
}

void	ft_boardinit(t_b *board, char *path)
{
	char	**lines;
	int		lines_size;
	int		i;
	int		len_line0;
	char	size_atoi[10];


	lines = ft_filegetlines(path);
	lines_size = ft_getlinesnum(lines);

	printf("\n(4)%d\n", ft_checkfile(lines, lines_size));

	len_line0 = ft_strlen(lines[0]);
	board->path = ft_strdup(path);
	board->x_size = ft_strlen(lines[1]);
	board->y_size = ft_atoi_b(ft_strncpy(size_atoi, lines[0], len_line0 - 3));
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

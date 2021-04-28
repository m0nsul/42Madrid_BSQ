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

int	ft_checkfile_chars(char **lines, int lines_size)
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
		while (++j < line_len)
			if (lines[i][j] != lines[0][len_line0 - 3]
				&& lines[i][j] != lines[0][len_line0 - 2])
				return (0);
	}
	return (1);
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
		return (0);
	len_line0 = ft_strlen(lines[0]);
	if (lines_size < 2 || (!(ft_check_first_line(lines[0]))))
		return (0);
	line_width = ft_strlen(lines[1]);
	y_size = ft_atoi_b(ft_strncpy(size_atoi, lines[0], len_line0 - 3));
	if (y_size != lines_size - 1)
		return (0);
	while (++i < lines_size)
		if ((ft_strlen(lines[i]) != line_width)
			|| ft_strlen(lines[i]) < 1)
			return (0);
	if (!(ft_checkfile_chars(lines, lines_size)))
		return (0);
	return (1);
}

int	ft_boardinit(t_b *board, char *path)
{
	char	**lines;
	int		i;
	int		len_line0;
	char	size_atoi[10];

	lines = ft_filegetlines(path);
	if (!lines || !(ft_checkfile(lines, ft_getlinesnum(lines))))
		return (0);
	len_line0 = ft_strlen(lines[0]);
	ft_strcpy(board->path, path);
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
	return (1);
}

int	ft_boardcreate(t_b	*board, char *path)
{
	board->error = 0;
	board->x_size = 0;
	board->y_size = 0;
	board->squares = NULL;
	if (!(ft_boardinit(board, path)))
	{
		board->error = 1;
		return (0);
	}
	ft_squarescalculate(board);
	ft_boardinitsolutions(board);
	ft_boardprint_solutions(board);
	return (1);
}

void	ft_boardfree(t_b *board)
{
	if (board && board->squares)
		ft_squaresfree(board);
	if (board->squares)
		free(board->squares);
	if (board)
		free(board);
}

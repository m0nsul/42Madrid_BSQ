#include <stdlib.h>
#include <stdio.h>
#include "ft_board.h"
#include "ft_file_io.h"
#include "ft_str.h"
#include "ft_board_print.h"
#include "ft_split.h"

int	ft_sqcalcneigh(t_b *board, int i, int j)
{
	int	min;

	if (i == board->y_size - 1 || j == board->x_size - 1
		|| board->squares[i][j]->type == obs)
	{
		board->squares[i][j]->neighcalc = board->squares[i][j]->type;
		return (board->squares[i][j]->neighcalc);
	}
	min = board->squares[i + 1][j]->neighcalc;
	if (board->squares[i][j + 1]->neighcalc < min)
		min = board->squares[i][j + 1]->neighcalc;
	if (board->squares[i + 1][j + 1]->neighcalc < min)
		min = board->squares[i + 1][j + 1]->neighcalc;
	board->squares[i][j]->neighcalc += min;
	return (board->squares[i][j]->neighcalc);
}

void	ft_squarescalculate(t_b *board)
{
	int	i;
	int	j;
	int	solution_max;
	int	partial;

	partial = 0;
	solution_max = 0;
	i = board->y_size;
	while (--i >= 0)
	{
		j = board->x_size;
		while (--j >= 0)
		{
			partial = ft_sqcalcneigh(board, i, j);
			if (partial > solution_max)
				solution_max = partial;
		}
	}
	board->solution_max = solution_max;
}

void	ft_squaresinit(t_b *board, char **lines)
{
	int	i;
	int	j;

	i = -1;
	while (++i < board->y_size)
	{
		j = -1;
		while (++j < board->x_size)
		{
			board->squares[i][j] = (t_bsq *)malloc(sizeof(t_bsq));
			if (lines[i + 1][j] == board->free)
				board->squares[i][j]->type = fr;
			else
				board->squares[i][j]->type = obs;
			board->squares[i][j]->neighcalc = board->squares[i][j]->type;
			board->squares[i][j]->is_solution = 0;
		}
	}
}

void	ft_squaresfree(t_b *board)
{
	int	i;
	int	j;

	i = -1;
	while (++i < board->y_size)
	{
		j = -1;
		while (++j < board->x_size)
			free(board->squares[i][j]);
	}
	i = -1;
	while (++i < board->y_size)
		free(board->squares[i]);
}

void	ft_boardinitsolutions(t_b *board)
{
	int	i;
	int	j;

	i = -1;
	while (++i < board->y_size)
	{
		j = -1;
		while (++j < board->x_size)
			if (board->squares[i][j]->neighcalc == board->solution_max)
				board->squares[i][j]->is_solution = 1;
	}
}

#include <stdlib.h>
#include <stdio.h>
#include "ft_board.h"
#include "ft_file_io.h"
#include "ft_str.h"

void	ft_boardprint_solution(t_b *board, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	ft_putchar('\n');
	while (++i < board->y_size)
	{
		j = -1;
		while (++j < board->x_size)
		{
			if ((i >= y && i <= y + board->solution_max - 1)
				&& (j >= x && j <= x + board->solution_max - 1))
				ft_putchar(board->aqchar);
			else if (board->squares[i][j]->type == fr)
				ft_putchar(board->free);
			else
				ft_putchar(board->obst);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

void	ft_boardprint_solutions(t_b *board)
{
	int	i;
	int	j;
	int	n;

	n = 1;
	i = -1;
	while (++i < board->y_size)
	{
		j = -1;
		while (++j < board->x_size)
			if (board->squares[i][j]->is_solution)
			{
				//printf("\n\n\nBoard %s Solution %d:\n\n", board->path, n++);
				ft_boardprint_solution(board, j, i);
				return ;
			}
	}
}

void	ft_boardprint_views(t_b *board)
{
	int	i;
	int	j;

	i = -1;
	while (++i < board->y_size)
	{
		j = -1;
		while (++j < board->x_size)
		{
			if (board->squares[i][j]->type == fr)
				ft_putchar(board->free);
			else
				ft_putchar(board->obst);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

void	ft_boardprint(t_b *board)
{
	printf("\nBoard Details:\n");
	printf("\n\tpath:\t%s", board->path);
	printf("\n\tx_size:\t%d", board->x_size);
	printf("\n\ty_size:\t%d", board->y_size);
	printf("\n\tfree:\t%c", board->free);
	printf("\n\tobst:\t%c", board->obst);
	printf("\n\taqchar:\t%c", board->aqchar);
	printf("\n\tssize:\t%d", board->solution_max);
	printf("\n\n\nBoard Original view:\n\n");
	ft_boardprint_views(board);
	// printf("\nBoard Neighbors view:\n");
	// printf("\nBoard Neighbors view:\n");
	// ft_boardprint_views(board, "solutions");
}
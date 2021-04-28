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
		}
		ft_putchar('\n');
	}
}

// Añadir en linea 43 para no imprimir 
// tablero sin solucion: && board->solution_max > 0
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
		{
			if (board->squares[i][j]->is_solution)
			{
				ft_boardprint_solution(board, j, i);
				return ;
			}
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
		}
		ft_putchar('\n');
	}
}

#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "ft_board.h"
#include "ft_str.h"

void	ft_put_error(void)
{
	write(1, "map error", 9);
	write(1, "\n", 1);
}
char	*ft_file_missing(void)
{
	char	buf;
	int		file;

	if ((file = open("tempgrid", O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0)
		return (NULL);
	while (read(STDIN_FILENO, &buf, 1) != 0)
	{
		write(file, &buf, 1);
	}
	close(file);
	return ("tempgrid");
}


int	check_main(int argc, char **argv)
{
	if (!(ft_strlen(argv[0])) && argc == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	// TODO: cambiar printf a write
	// TODO: Quitar header que no se utilicen
	t_b	*board;
	int	n;

	board = NULL;
	if (argc == 1)
	{
		if (!(ft_boardcreate(board, ft_file_missing())))
		{
			ft_put_error();
			ft_boardfree(board);
		}
	}
	if (check_main(argc, argv)) // TODO: hacer los checks de argumentos
	{
		n = 0;
		while (++n < argc)
		{
			board = (t_b *) malloc (sizeof(t_b));
			if (!board)
				return (0);
			if (!(ft_boardcreate(board, argv[n])))
			{
				ft_put_error();
				ft_boardfree(board);
			}
			if (n < argc - 1)
				ft_putchar('\n');
		}
	}
	else
	{
		ft_put_error();
		return (0);
	}
	return (1);
}

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_board.h"
#include "ft_str.h"

void	ft_put_error(void)
{
	write(1, "map error", 9);
	write(1, "\n", 1);
}

char	*ft_file_path(int argc, char **argv, int n)
{
	char	buf;
	int		file;

	if (argc > 1)
		return (argv[n]);
	file = open("tempgrid", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file < 0)
		return (NULL);
	while (read(STDIN_FILENO, &buf, 1) != 0)
	{
		write(file, &buf, 1);
	}
	close(file);
	return ("tempgrid");
}

int	main(int argc, char **argv)
{
	t_b		*board;
	int		n;

	n = -1;
	while (++n < argc)
	{
		board = (t_b *) malloc (sizeof(t_b));
		if (!board)
			return (0);
		if (!(ft_boardcreate(board, ft_file_path(argc, argv, n + 1))))
			ft_put_error();
		if (n + 1 < argc - 1)
			ft_putchar('\n');
		ft_boardfree(board);
		if (n == argc - 2)
			break ;
	}
	return (1);
}

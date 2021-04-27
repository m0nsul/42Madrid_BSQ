#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "ft_board.h"
#include "ft_str.h"

char	*ft_file_missing(void)
{
	char	buf;
	int		file;

	if ((file = open("tempgrid", O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0)
		return (NULL);
	while (read(STDIN_FILENO, &buf, 1))
	{
		write(file, &buf, 1);
	}
	close(file);
	return ("tempgrid");
}

int	check_main(int argc, char **argv)
{
	if (argc == 1)
	{
		argv[1] = (char *) malloc (9 * sizeof(char));
		ft_strcpy(argv[1], ft_file_missing());
		argc++;
		return (1);

	}
	if (!(ft_strlen(argv[0])))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	// TODO: cambiar printf a write
	// TODO: Quitar header que no se utilicen
	// TODO: Función exit para qué?
	// TODO: leer cuadrado por entrada estandar
	// TODO: Validar mapa
	t_b	*board;
	int	n;

	if (argc == 1)
	{
		board = ft_boardcreate(ft_file_missing());
		ft_boardfree(board);
	}
	if (check_main(argc, argv)) // TODO: hacer los checks de argumentos
	{
		n = 0;
		while (++n < argc)
		{
			board = ft_boardcreate(argv[n]);
			ft_boardfree(board);
			if (n < argc - 1)
				write(1, "\n", 1);
		}
	}
	else
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
	}
	return (1);
}

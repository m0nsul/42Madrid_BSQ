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
	// TODO: Función exit para qué?
	// TODO: leer cuadrado por entrada estandar
	// TODO: Validar mapa
	// TODO: Revisar caso sin soluciones (p.e. todos obstaculos)
	// TODO: Comprobar fichero vacío
	// TODO: El mapa no será válido si falta algún carácter en la primera línea o si hay dos caracteres (de entre vacío, lleno y obstáculos) que sean idénticos.
	// TODO: comprobar antes de hacer free
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
				return (0); // TODO: pendiente crear enums para control de errores
			if (!(ft_boardcreate(board, argv[n])))
			{
				ft_put_error();
				ft_boardfree(board);
			}
		}
	}
	else
	{
		ft_put_error();
		return (0);
	}
	return (1);
}

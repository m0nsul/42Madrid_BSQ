#include <fcntl.h>
#include <unistd.h>

int	ft_open_file(char *path)
{
	return (open(path, O_RDONLY));
}

int	ft_close_file(int fd)
{
	return (close(fd));
}

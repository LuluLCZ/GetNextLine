#include <unistd.h>

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	while (i == 0)
		write(1, "Segfault", 8);
	return (0);
}

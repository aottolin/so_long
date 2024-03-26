#include "so_long_lib.h"

int	ft_strlen2(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

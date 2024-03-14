#include "so_long_lib.h"

void	*ft_memory(size_t count, size_t size)
{
	void	*bzero;
	size_t	x;
	char	c;

	c = '0';
	x = 0;
	bzero = (void *)malloc(count * size);
	if (!bzero)
		return (NULL);
	while (x < (count * size))
	{
		((char *)bzero)[x] = c;
		x++;
	}
	return (bzero);
}

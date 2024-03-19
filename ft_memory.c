#include "so_long_lib.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*bzero;

	bzero = (void *)malloc(count * size);
	if (!bzero)
		return (0);
	ft_bzero (bzero, count * size);
	return (bzero);
}

/*
 * void	*ft_memory(size_t count, size_t size)
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
}*/

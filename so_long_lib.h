# ifndef SO_LONG_LIB_H
# define SO_LONG_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf/ft_printf.h"

typedef struct	d_list
{
	void	*mlx;
	void	*win;
	int		moves;
}	d_list;

void	*ft_memory(size_t count, size_t size);
int		ft_strlen2(char *str);
void	ft_error(d_list *d, int nb);
#endif

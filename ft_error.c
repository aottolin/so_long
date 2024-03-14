#include "so_long_lib.h"

void	ft_error(d_list *d, int nb)
{
	if (nb == 1)
		ft_printf("ERROR!! -El argumento debe ser una extension .ber");
	free(d);
}

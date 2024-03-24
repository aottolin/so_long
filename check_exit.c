#include "so_long_lib.h"
#include "../so_long/mlx/mlx.h"

int	check_exit(d_list *d, char letter)
{
	if (letter == 'E' && d->consum == 0)
	{
		ft_printf("🏆WINNER🏆 has completado el juego!\n");
		ft_free(d);
	}
	if (letter == 'E' && d->consum != 0)
	{
		ft_printf("El juego no termina hasta que no recoges todos los consumibles\n");
		return (1);
	}
	else
		return (0);
}

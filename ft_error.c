#include "so_long_lib.h"

void	ft_error2(d_list *d, int nb)
{
	d->moves++;
	d->moves--;
	if (nb == 9)
		ft_printf("❌ERROR❌ --->No se puede leer el mapa");
}

void	ft_error(d_list *d, int nb)
{
	ft_printf("Error\n");
	if (nb == 1)
		ft_printf("❌ERROR❌ ---->El argumento debe ser una extension .ber\n");
	if (nb == 2)
		ft_printf("❌ERROR❌ ---->El mapa contiene caracteres incorrectos\n");
	if (nb == 3)
		ft_printf("❌ERROR❌ ---->El mapa debe estar rodeado de muros\n");
	if (nb == 5 && d->exx < 1)
		ft_printf("❌ERROR❌ ----->El mapa debe contener 1 salida\n");
	if (nb == 5 && d->exx > 1)
		ft_printf("❌ERROR❌ ------>El mapa debe contener SOLO 1 salida\n");
	if (nb == 5 && d->player < 1)
		ft_printf("❌ERROR❌  ----->El mapa debe contener un jugador en posicion inicial\n");
	if (nb == 5 && d->player > 1)
		ft_printf("❌ERROR❌ - ---->El mapa debe contener UN SOLO jugador en posicion inicial\n");
	if (nb == 5 && d->consum < 1)
		ft_printf("❌ERROR❌ ----->El juego debe tener al menos 1 consumible\n");
	if (nb == 7)
		ft_printf("❌ERROR❌ ---->El mapa no es rectangular\n");
	if (nb > 7)
		ft_error2(d, nb);
	ft_free(d);
}

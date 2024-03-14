#include "so_long_lib.h"

void	check_extension(char *ext, d_list *d);

int	main(int argc, char **argv)
{
	d_list	*d;

	if (argc != 2)
	{
		ft_printf("El numero de argumentos es incorrecto\n");
		ft_printf("%s\n", argv[1]);
		return (0);
	}
	d = ft_memory(1, sizeof(t_list));
	if (!d)
		return (0);
	d->mlx = mlx_init();
	init_data(d, argv[1]);
	return (0);
}

int	init_data(d_list *d, char *map)
{
	d->moves = 0;
	check_extension(map, d);


}

void	check_extension(char *ext, d_list *d)
{
	int	x;

	x = ft_strlen2(ext);
	if (x > 2 && ext[x - 4] == '.' && ext[x - 3] == 'b'
			&& ext[x - 2] == 'e' && ext[x - 1] == 'r')
		return ;
	else
		ft_error(d, 1);
}

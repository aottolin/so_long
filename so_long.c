#include "so_long_lib.h"
#include "../so_long/mlx/mlx.h"

int	main(int argc, char **argv)
{
	d_list	*d;

	if (argc != 2)
	{
		ft_printf("El numero de argumentos es incorrecto\n");
		ft_printf("%s\n", argv[1]);
		return (0);
	}
	d = ft_calloc(1, sizeof(d_list));
	if (!d)
		return (0);
	d->mlx = mlx_init();
	init_data(d, argv[1]);
	mlx_loop(d->mlx);
	ft_free(d);
	return (0);
}

int	init_data(d_list *d, char *map)
{
	d->moves = 0;
	check_extension(map, d);
	read_map(map, d);
	init_img(d);
	d->win = mlx_new_window(d->mlx, d->x, d->y, "so_long");
	print_map(d);
	return (0);
}

void	init_img(d_list *d)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	d->y = (ft_strlen2(d->content) / d->width_d + 1) * 50;
	d->x = (d->width_d - 1) * 50;
	d->img_fond = mlx_xpm_file_to_image(d->mlx, "img_fond.xpm", &w, &h);
	d->img_food = mlx_xpm_file_to_image(d->mlx, "img_food.xpm", &w, &h);
	d->img_exit = mlx_xpm_file_to_image(d->mlx, "img_exit.xpm", &w, &h);
	d->img_walls = mlx_xpm_file_to_image(d->mlx, "img_walls.xpm", &w, &h);
	d->img_player = mlx_xpm_file_to_image(d->mlx, "img_player.xpm", &w, &h);

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

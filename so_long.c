/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aottolin <aottolin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:07:10 by aottolin          #+#    #+#             */
/*   Updated: 2024/03/27 12:07:11 by aottolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"
#include "../so_long/mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_list	*d;

	if (argc != 2)
	{
		ft_printf("El numero de argumentos es incorrecto\n");
		ft_printf("%s\n", argv[1]);
		return (0);
	}
	d = ft_calloc(1, sizeof(t_list));
	if (!d)
		return (0);
	init_data(d, argv[1]);
	mlx_key_hook(d->win, key_press, d);
	mlx_hook(d->win, 17, 0, ft_free, d);
	mlx_loop(d->mlx);
	ft_free(d);
	return (0);
}

int	init_data(t_list *d, char *map)
{
	int	x_offset;
	int	y_offset;

	x_offset = 0;
	y_offset = 0;
	d->moves = 0;
	check_extension(map, d);
	read_map(map, d);
	d->mlx = mlx_init();
	init_img(d);
	d->win = mlx_new_window(d->mlx, d->x, d->y, "so_long");
	while (y_offset < d->y)
	{
		x_offset = 0;
		while (x_offset < d->x)
		{
			mlx_put_image_to_window(d->mlx, d->win,
				d->background, x_offset, y_offset);
			x_offset += 50;
		}
		y_offset += 50;
	}
	print_map(d);
	return (0);
}

void	init_img(t_list *d)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	d->y = (ft_strlen2(d->content) / d->width_d + 1) * 50;
	d->x = (d->width_d - 1) * 50;
	d->background = mlx_xpm_file_to_image(d->mlx, "img/img_fondo.xpm", &w, &h);
	d->img_food = mlx_xpm_file_to_image(d->mlx, "img/img_food.xpm", &w, &h);
	d->img_exit = mlx_xpm_file_to_image(d->mlx, "img/img_exit.xpm", &w, &h);
	d->img_walls = mlx_xpm_file_to_image(d->mlx, "img/img_walls.xpm", &w, &h);
	d->img_fond = mlx_xpm_file_to_image(d->mlx, "img/img_fondo.xpm", &w, &h);
	d->img_player = mlx_xpm_file_to_image(d->mlx, "img/img_p.xpm", &w, &h);
	d->img_p_front = mlx_xpm_file_to_image(d->mlx, "img/img_p.xpm", &w, &h);
	d->img_p_left = mlx_xpm_file_to_image(d->mlx, "img/img_p_left.xpm", &w, &h);
	d->img_p_right = mlx_xpm_file_to_image(d->mlx, "img/img_p_ri.xpm", &w, &h);
	d->img_p_back = mlx_xpm_file_to_image(d->mlx, "img/img_p_back.xpm", &w, &h);
}

void	check_extension(char *ext, t_list *d)
{
	int	x;

	x = ft_strlen2(ext);
	if (x > 2 && ext[x - 4] == '.' && ext[x - 3] == 'b'
		&& ext[x - 2] == 'e' && ext[x - 1] == 'r')
		return ;
	else
		ft_error(d, 1);
}

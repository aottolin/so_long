#include "so_long_lib.h"
#include "../so_long/mlx/mlx.h"

void	print_map(t_list *d)
{
	int	x;

	x = 0;
	while (d->content[x] != '\0')
	{
		if (d->content[x] == '\n')
			x++;
		if (d->content[x] != 'C' && d->content[x] != 'P'
			&& d->content[x] != '1' && d->content[x] != 'E'
			&& d->content[x] != '0')
			exit(0);
		if (d->content[x] == 'C')
			calcul_y_x('C', x, d);
		if (d->content[x] == 'P')
			calcul_y_x('P', x, d);
		if (d->content[x] == '1')
			calcul_y_x('1', x, d);
		if (d->content[x] == 'E')
			calcul_y_x('E', x, d);
		if (d->content[x] == '0')
			calcul_y_x('0', x, d);
		x++;
	}
}

void	calcul_y_x(char c, int iter, t_list *d)
{
	int	x_;
	int	y_;

	y_ = (iter / d->width_d) * 50;
	x_ = (iter % d->width_d) * 50;
	if (d->errors == 0)
	{
		if (c == 'C')
			mlx_put_image_to_window(d->mlx, d->win, d->img_food, x_, y_);
		if (c == 'E')
			mlx_put_image_to_window(d->mlx, d->win, d->img_exit, x_, y_);
		if (c == '1')
			mlx_put_image_to_window(d->mlx, d->win, d->img_walls, x_, y_);
		if (c == '0')
			mlx_put_image_to_window(d->mlx, d->win, d->img_fond, x_, y_);
		if (c == 'P')
			mlx_put_image_to_window(d->mlx, d->win, d->img_player, x_, y_);
	}
}

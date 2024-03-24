#include "so_long_lib.h"
#include "../so_long/mlx/mlx.h"

int	key_press(int key, d_list *d)
{
	(void)d;
	if (key == 53)
	{
		mlx_destroy_window(d->mlx, d->win);
		ft_free(d);
	}
	if (key == 13)
		move_w(d);
	if (key == 0)
		move_a(d);
	if (key == 1)
		move_s(d);
	if (key == 2)
		move_d(d);
	ft_printf("%d\n", d->moves);
	return (0);
}

void	move_w(d_list *d)
{
	int x;

	x = 0;
	while(d->content[x] != 'P')
		x++;
	if (d->content[x - d->width_d] != '1'
			&& !check_exit(d, d->content[x - d->width_d]))
	{
		d->moves++;
		if (d->content[x - d->width_d] == 'C')
			d->consum--;
		d->content[x] = '0';
		d->content[x - d->width_d] = 'P';
		d->img_player = d->img_player_back;
	}
	print_map(d);
}

void	move_a(d_list *d)
{
	int	x;

	x = 0;
	while (d->content[x] != 'P')
		x++;
	if (d->content[x - 1] != '1'
			&& !check_exit(d, d->content[x - 1]))
	{
		d->moves++;
		if (d->content[x - 1] == 'C')
			d->consum--;
		d->content[x] = '0';
		d->content[x - 1] = 'P';
		d->img_player = d->img_player_left;
	}
	print_map(d);
}

void	move_s(d_list *d)
{
	int	x;

	x = 0;
	while (d->content[x] != 'P')
		x++;
	if (d->content[x + d->width_d] != '1'
			&& !check_exit(d, d->content[x + d->width_d]))
	{
		d->moves++;
		if (d->content[x + d->width_d] == 'C')
			d->consum--;
		d->content[x] = '0';
		d->content[x + d->width_d] = 'P';
		d->img_player = d->img_player_front;
	}
	print_map(d);
}

void	move_d(d_list *d)
{
	int x;

	x = 0;
	while (d->content[x] != 'P')
		x++;
	if (d->content[x + 1] != '1'
			&& !check_exit(d, d->content[x + 1]))
	{
		d->moves++;
		if (d->content[x + 1] == 'C')
			d->consum--;
		d->content[x] = '0';
		d->content[x + 1] = 'P';
		d->img_player = d->img_player_right;
	}
	print_map(d);
}

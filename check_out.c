#include "so_long_lib.h"
#include "../so_long/mlx/mlx.h"

void	check_out(d_list *d)
{
	int	x;
	int e_pos;

	x = 0;
	e_pos = 0;
	while (d->content[e_pos] != 'E')
		e_pos++;
	while (d->content[x] != 'P')
		x++;
	if (e_pos < x)
	{
		while (d->content[x] != 'E')
		{
			if (d->content[x + 1] == '1' && d->content[x - d->width_d] == '1'
					&& d->content[x - 1] == '1' && d->content[x + d->width_d] == '1')
			{
				ft_printf("d c:%c\n", d->content[x]);
				ft_printf("x - 1:%c\n", d->content[x - 1]);
				ft_printf("x + 1:%c\n", d->content[x + 1]);
				ft_printf("x + d-w:%c\n", d->content[x + d->width_d]);
				ft_printf("x - d-w:%c\n", d->content[x - d->width_d]);
				ft_printf("pos:%d\n", x);
				ft_error(d, 8);
			}
			else
				x--;
		}
	}
	else if (e_pos > x)
	{
		while (d->content[x] != 'E')
		{
			if (d->content[x + 1] == '1' && d->content[x - d->width_d] == '1'
					&& d->content[x - 1] == '1' && d->content[x + d->width_d] == '1')
				ft_error(d, 8);
			else
				x++;
		}
	}
}

#include "so_long_lib.h"

void	check_first_last_line(t_list *d)
{
	int	i;
	int	last;

	i = 0;
	last = ft_strlen2(d->content) - d->width_d;
	while (i != d->width_d)
	{
		if (d->content[i] == '1' || d->content[i] == '\n')
			i++;
		else
			ft_error(d, 3);
	}
	while (last != ft_strlen2(d->content))
	{
		if (d->content[last] == '1' || d->content[last] == '\n')
			last++;
		else
			ft_error(d, 3);
	}
	check_start_line(d);
}

void	check_start_line(t_list *d)
{
	int	i;

	i = d->width_d - 2;
	while (i < ft_strlen2(d->content))
	{
		if (d->content[i] == '1')
			i = i + d->width_d;
		else
			ft_error(d, 2);
	}
	i = d->width_d;
	while (i < ft_strlen2(d->content))
	{
		if (d->content[i] == '1')
			i = i + d->width_d;
		else
			ft_error(d, 3);
	}
}

void	check_line_break(char *line, t_list *d)
{
	int	x;

	x = 0;
	d->linecontrol = 1;
	while (line[x])
	{
		if (line[x] == '\n')
			d->linecontrol = 0;
		x++;
	}
}

#include "so_long_lib.h"

void	read_map(char *map, t_list *d)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error(d, 10);
	ft_init(d);
	while (d->linecontrol != 1)
	{
		d->height++;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (d->linecontrol == 2)
			d->width_d = ft_strlen2(line);
		check_line_break(line, d);
		if ((ft_strlen2(line) + d->linecontrol) != d->width_d)
			ft_error(d, 7);
		d->content = str_join(d->content, line);
		if (line)
			free(line);
	}
	close(fd);
	check_first_last_line(d);
	checkline(d);
}

void	ft_init(t_list *d)
{
	d->linecontrol = 2;
	d->width_d = 0;
	d->height = 0;
	d->player = 0;
	d->exx = 0;
	d->content = (char *)malloc(sizeof(char) * 1);
	if (!d->content)
		return ;
}

void	ft_check_errors(t_list *d, int counter)
{
	if (counter == d->width_d)
		ft_error(d, 7);
	if (d->exx != 1 || d->player != 1 || d->consum < 1)
		ft_error(d, 5);
}

void	checkline(t_list *d)
{
	int	x;
	int	counter;

	counter = 1;
	x = -1;
	while (d->content[++x])
	{
		if (d->content[x] != '1' && d->content[x] != '0'
			&& d->content[x] != 'C' && d->content[x] != 'E'
			&& d->content[x] != 'P' && d->content[x] != '\n')
			ft_error(d, 2);
		if (d->content[x] == '\n')
			counter++;
		if (d->content[x] == 'C')
			d->consum++;
		if (d->content[x] == 'E')
			d->exx++;
		if (d->content[x] == 'P')
			d->player++;
		if (d->content[x] == '1')
			d->wall++;
		if (d->content[x] == '0')
			d->space_free++;
	}
	ft_check_errors(d, counter);
}

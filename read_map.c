#include "so_long_lib.h"

void	read_map(char *map, d_list *d)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_free(d);
	d->linecontrol = 2;
	while (d->linecontrol != 1)
	{
		d->height++;
		line = get_next_line(fd);
		//if (!line)
		//	ft_error(d, 9);
		if (d->linecontrol == 2)
			d->width = ft_strlen2(line);
		check_line_break(line, d);
		//if (ft_strlen2(line) + d->linecontrol != d->width)
		//	ft_error(d, 7);
		d->big_line = str_join(d->big_line, line);
		if (line)
			free(line);
	}
	close(fd);
	checkline(d);
}

void	checkline(d_list *d)
{
	int	x;

	x = 0;
	d->player = 0;
	ft_printf("%s", d->big_line);
	while (d->big_line[x])
	{
		if (d->big_line[x] != '1' && d->big_line[x] != '0' 
				&& d->big_line[x] != 'C' && d->big_line[x] != 'E' 
				&& d->big_line[x] != 'P' && d->big_line[x] != '\n')
			ft_error(d, 2);
		if (d->big_line[x] == 'C')
			d->consum++;
		if (d->big_line[x] == 'E')
			d->exx++;
		if (d->big_line[x] == 'P')
			d->player++;
		if (d->big_line[x] == '1')
			d->wall++;
		if (d->big_line[x] == '0')
			d->space_free++;
		x++;
	}
	ft_printf("consum:%d\n", d->consum);
	ft_printf("exx:%d\n", d->exx);
	ft_printf("player:%d\n", d->player);
	ft_printf("wall:%d\n", d->wall);
	ft_printf("space_free:%d\n", d->space_free);
	if (d->exx != 1 || d->player != 1 || d->consum < 1)
		ft_error(d, 5);
}

void	check_line_break(char *line, d_list *d)
{
	int	x;

	x = 0;
	d->linecontrol = 1;
	if (!line)
		return ;
	while (line[x])
	{
		if (line[x] == '\n')
			d->linecontrol = 0;
		x++;
	}
}

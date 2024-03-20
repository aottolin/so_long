#include "so_long_lib.h"

void	read_map(char *map, d_list *d)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_free(d);
	d->linecontrol = 2;
	d->width_d = 0;
	d->height = 0;
	d->content = (char *)malloc(sizeof(char) * 1);
	if (!d->content)
		return ;
	while (d->linecontrol != 1)
	{
		d->height++;
		line = get_next_line(fd);
		if (!line)
			break;
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

void	checkline(d_list *d)
{
	int	x;
	int	counter;

	counter = 1;
	x = 0;
	d->player = 0;
	d->exx = 0;
	ft_printf("DCONENT:\n%s", d->content);
	while (d->content[x])
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
		x++;
	}
	if (counter == d->width_d)
		ft_error(d, 7);
	if (d->exx != 1 || d->player != 1 || d->consum < 1)
		ft_error(d, 5);
}

void	check_first_last_line(d_list *d)
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

void	check_start_line(d_list *d)
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

void	check_line_break(char *line, d_list *d)
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

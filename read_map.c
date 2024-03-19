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
	while (d->linecontrol != 1)
	{
		d->height++;
		ft_printf("wid%d\n", d->width_d);
		line = get_next_line(fd);
		ft_printf("%s", line);
		if (!line)
			break;
		if (d->linecontrol == 2)
			d->width_d = ft_strlen2(line);
		check_line_break(line, d);
		ft_printf("wid%d\n", d->width_d);
		ft_printf("linec%d\n", d->linecontrol);
		ft_printf("strl%d\n", ft_strlen2(line));
		if ((ft_strlen2(line) + d->linecontrol) != d->width_d)
		{
			ft_printf("wid%d\n", d->width_d);
			ft_error(d, 7);
		}
		ft_printf("wid%d\n", d->width_d);
		d->content = str_join(d->content, line);
		ft_printf("wid%d\n", d->width_d);
		//if (!line)
		//	free(line);
	}
	free(line);
	close(fd);
	checkline(d);
}

void	checkline(d_list *d)
{
	int	x;
	int	counter;

	counter = 1;
	x = 0;
	d->player = 0;
	ft_printf("DCONENT:%s", d->content);
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

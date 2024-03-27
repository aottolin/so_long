#include "so_long_lib.h"

int	valid_move(t_list *d, int *visited, int p_pos)
{
	return (d->content[p_pos] != '1' && !visited[p_pos]);
}

void	flood_fill(t_list *d, int p_pos, int *visited)
{
	if (!valid_move(d, visited, p_pos) || visited[p_pos])
		return ;
	if (d->content[p_pos] == 'C')
		d->flood_consum += 1;
	visited[p_pos] = 1;
	flood_fill(d, p_pos - d->width_d, visited);
	flood_fill(d, p_pos + d->width_d, visited);
	flood_fill(d, p_pos - 1, visited);
	flood_fill(d, p_pos + 1, visited);
}

void	exit_position(t_list *d)
{
	int	x;

	x = 0;
	while (d->content[x])
	{
		if (d->content[x] == 'E')
			d->exit_pos = x;
		if (d->content[x] == 'C')
			d->check_consum += 1;
		x++;
	}
}

void	player_position(t_list *d, int x, int *p_pos)
{
	d->flood_consum = 0;
	d->check_consum = 0;
	while (d->content[x])
	{
		if (d->content[x] == 'P')
		{
			*p_pos = x;
			break ;
		}
		x++;
	}
}

int	valid_path(t_list *d, int x, int p_pos)
{
	int	*visited;

	visited = ft_calloc(d->width_d * d->height, sizeof(int));
	x = 0;
	while (d->content[x])
	{
		player_position(d, x, &p_pos);
		x++;
	}
	exit_position(d);
	flood_fill(d, p_pos, visited);
	x = visited[p_pos] && visited[d->exit_pos];
	free(visited);
	if (d->flood_consum != d->consum || !x)
		ft_error(d, 12);
	return (0);
}

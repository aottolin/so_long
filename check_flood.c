/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkread_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aottolin <aottolin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:06:12 by aottolin          #+#    #+#             */
/*   Updated: 2024/03/27 12:09:54 by aottolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

int	valid_move(t_list *d, int *array, int p_pos)
{
	return (d->content[p_pos] != '1' && !array[p_pos]);
}

void	flood_fill(t_list *d, int p_pos, int *array)
{
	if (!valid_move(d, array, p_pos) || array[p_pos])
		return ;
	if (d->content[p_pos] == 'C')
		d->flood_consum += 1;
	array[p_pos] = 1;
	flood_fill(d, p_pos - d->width_d, array);
	flood_fill(d, p_pos + d->width_d, array);
	flood_fill(d, p_pos - 1, array);
	flood_fill(d, p_pos + 1, array);
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
	int	*array;

	array = ft_calloc(d->width_d * d->height, sizeof(int));
	x = 0;
	while (d->content[x])
	{
		player_position(d, x, &p_pos);
		x++;
	}
	exit_position(d);
	flood_fill(d, p_pos, array);
	x = array[p_pos] && array[d->exit_pos];
	free(array);
	if (d->flood_consum != d->consum || !x)
		ft_error(d, 12);
	check_windows_size(d);
	return (0);
}

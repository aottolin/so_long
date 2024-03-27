/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aottolin <aottolin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:06:47 by aottolin          #+#    #+#             */
/*   Updated: 2024/03/27 12:06:48 by aottolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

char	*str_chr(char *save, int newline)
{
	int	x;

	x = 0;
	if (!save)
		return (NULL);
	if (newline == '\0')
		return ((char *)&save[ft_strlen2(save)]);
	while (save[x] != newline && save[x] != '\0')
		x++;
	if (save[x] == newline)
		return (save);
	return (NULL);
}

char	*str_join(char *save, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!save)
	{
		save = (char *)malloc(sizeof(char) + 1);
		save[0] = '\0';
	}
	str = (char *)malloc(1 * (ft_strlen2(save) + ft_strlen2(s2) + 1));
	if (!str)
		return (0);
	i = -1;
	while (save[++i])
		str[i] = save[i];
	c = 0;
	while (s2[c])
	{
		str[i + c] = s2[c];
		c++;
	}
	str[i + c] = '\0';
	free(save);
	return (str);
}

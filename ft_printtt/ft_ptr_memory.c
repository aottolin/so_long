/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aottolin <aottolin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:04:35 by aottolin          #+#    #+#             */
/*   Updated: 2024/01/27 13:04:37 by aottolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_hex_adress(unsigned long long p, int len)
{
	char	*hex;
	int		result[20];
	int		i;

	if (len == -1)
		return (-1);
	hex = "0123456789abcdef";
	i = 0;
	while (p >= 16)
	{
		result[i] = hex[p % 16];
		p = p / 16;
		i++;
	}
	result[i] = hex[p];
	while (i >= 0)
	{
		len = ft_putchar_len(result[i], len);
		i--;
	}
	if (len == -1)
		return (-1);
	return (len);
}

int	ft_pointer(void *pointer, int len)
{
	if (pointer == NULL)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		len += 3;
		return (len);
	}
	len = ft_putstr_len("0x", len);
	len = ft_pointer_hex_adress((unsigned long long)pointer, len);
	return (len);
}

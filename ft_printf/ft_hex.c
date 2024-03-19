/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aottolin <aottolin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:52:02 by aottolin          #+#    #+#             */
/*   Updated: 2024/01/27 12:53:26 by aottolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nb, const char *format, int len, size_t j)
{
	if (nb >= 16)
	{
		len = ft_puthex(nb / 16, format, len, j);
		len = ft_puthex(nb % 16, format, len, j);
	}
	else
	{
		if (nb < 10)
			len = ft_putchar_len((nb + '0'), len);
		else
		{
			if (format[j] == 'x')
				len = ft_putchar_len((nb - 10 + 'a'), len);
			if (format[j] == 'X')
				len = ft_putchar_len((nb - 10 + 'A'), len);
		}
	}
	return (len);
}

int	ft_hex(unsigned int nb, const char *format, int len, size_t j)
{
	if (nb == 0)
	{
		len += (write(1, "0", 1));
		return (len);
	}
	else
		len = ft_puthex(nb, format, len, j);
	return (len);
}

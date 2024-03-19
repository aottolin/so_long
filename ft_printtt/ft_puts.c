/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aottolin <aottolin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:05:13 by aottolin          #+#    #+#             */
/*   Updated: 2024/01/27 13:05:18 by aottolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_len(char c, int len)
{
	if (len == -1)
		return (-1);
	else if (write(1, &c, 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_putstr_len(char *str, int len)
{
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		len += 6;
		return (len);
	}
	while (*str)
	{
		len = ft_putchar_len(*str, len);
		if (len == -1)
			return (-1);
		str++;
	}
	return (len);
}

int	ft_putnbr_len(int nb, int len)
{
	if (len == -1)
		return (-1);
	if (nb <= -2147483648)
	{
		len = ft_putchar_len('-', len);
		len = ft_putchar_len('2', len);
		len = ft_putnbr_len(147483648, len);
	}
	else if (nb < 0)
	{
		len = ft_putchar_len('-', len);
		len = ft_putnbr_len(-nb, len);
	}
	else if (nb >= 10)
	{
		len = ft_putnbr_len(nb / 10, len);
		len = ft_putnbr_len(nb % 10, len);
	}
	else
	{
		nb += '0';
		len = ft_putchar_len(nb, len);
	}
	return (len);
}

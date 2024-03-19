/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aottolin <aottolin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:54:57 by aottolin          #+#    #+#             */
/*   Updated: 2024/01/27 13:01:49 by aottolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(va_list args, const char *format, int len,
size_t j)
{
	if (format[j] == 'c')
		len = ft_putchar_len(va_arg(args, int), len);
	else if (format[j] == 's')
		len = ft_putstr_len(va_arg(args, char *), len);
	else if (format[j] == 'p')
		len = ft_pointer(va_arg(args, void *), len);
	else if (format[j] == 'd' || format[j] == 'i')
		len = ft_putnbr_len(va_arg(args, int), len);
	else if (format[j] == 'u')
		len = ft_unsigned(va_arg(args, unsigned int), len);
	else if (format[j] == 'x' || format[j] == 'X')
		len = ft_hex(va_arg(args, unsigned int), format, len, j);
	else if (format[j] == '%')
		len = ft_putchar_len('%', len);
	if (len == -1)
		return (-1);
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	j;
	int		len;

	va_start(args, format);
	j = -1;
	len = 0;
	while (format[++j])
	{
		if (format[j] == '%')
		{
			len = ft_printf_format(args, format, len, j + 1);
			j++;
		}
		else
			len = ft_putchar_len(format[j], len);
		if (len == -1)
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);
	return (len);
}

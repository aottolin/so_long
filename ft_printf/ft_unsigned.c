/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aottolin <aottolin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:05:34 by aottolin          #+#    #+#             */
/*   Updated: 2024/01/27 13:05:35 by aottolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int nb, int len)
{
	if (nb >= 10)
	{
		len = ft_putnbr_len(nb / 10, len);
		len = ft_putnbr_len(nb % 10, len);
	}
	else
		len = ft_putchar_len(nb + '0', len);
	return (len);
}

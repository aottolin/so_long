/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aottolin <aottolin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:01:55 by aottolin          #+#    #+#             */
/*   Updated: 2024/01/27 13:03:10 by aottolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

int		ft_printf(char const *format, ...);
int		ft_putchar_len(char c, int len);
int		ft_putstr_len(char *str, int len);
int		ft_pointer(void *pointer, int len);
int		ft_pointer_hex_adress(unsigned long long p, int size);
int		ft_putnbr_len(int nb, int len);
int		ft_unsigned(unsigned int nb, int len);
int		ft_hex(unsigned int nb, const char *format, int len, size_t j);
int		ft_puthex(unsigned int nb, const char *format, int len, size_t j);
#endif

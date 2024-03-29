/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aottolin <aottolin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:50:58 by aottolin          #+#    #+#             */
/*   Updated: 2024/01/16 15:28:11 by aottolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**************************************************************
*						FT_SPLIT:							  *
*	La función ft_split divide una cadena de caracteres (s)   *
*	en subcadenas utilizando un carácter delimitador (c).     *
*	Devuelve un arreglo de cadenas de caracteres (matriz de   *
*	cadenas) donde cada elemento es una subcadena.            *
*															  *
*	Argumentos:												  *
*	s: La cadena de caracteres que se dividirá en subcadenas. *
*	c: El carácter delimitador utilizado para dividir la      *
*	cadena.													  *
*															  *	
\*************************************************************/

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	contador;
	int	warn;

	contador = 0;
	warn = 0;
	while (*str)
	{
		if (*str != c && warn == 0)
		{
			warn = 1;
			contador++;
		}
		else if (*str == c)
			warn = 0;
		str++;
	}
	return (contador);
}

static char	**free_m(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		--i;
	}
	free(split);
	return (NULL);
}

static int	len_word(char const *s, char c)
{
	int	counter;

	counter = 0;
	while (*s == c)
		s++;
	while (*s != c && *s)
	{
		counter++;
		s++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count_words(s, c))
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		array[i] = ft_substr(s, j, len_word(&s[j], c));
		if (!array[i])
			return (free_m(array, i));
		j += len_word(&s[j], c);
		i++;
	}
	array[i] = 0;
	return (array);
}
/*
int	main(void)	
{
	char str[] = "AlexisAlenAlejoAlario";
	char **str1;

	str1 = ft_split(str, 'A');
	while (*str1)
		printf("%s\n", *str1++);
	return (0);
}*/

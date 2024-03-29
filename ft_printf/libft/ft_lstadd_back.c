/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aottolin <aottolin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:40:11 by aottolin          #+#    #+#             */
/*   Updated: 2024/01/17 13:44:15 by aottolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_lists **lst, t_lists *new)
{
	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
/*
void	is_print(t_lists *print)
{
	while (print)
	{
		printf("t_lists %s\n", (char *)print->content);
		print = print->next;
	}
}

int	main(void)
{
	t_lists	*ato;
	t_lists	*palabra4;

	ato = ft_lstnew("Palabra1");
	ato->next = ft_lstnew("Palabra2");
	ato->next->next = ft_lstnew("Palabra3");

	palabra4 = ft_lstnew("palabra4");

	ft_lstadd_back(&ato, palabra4);
	is_print(ato);
	return (0);
}*/

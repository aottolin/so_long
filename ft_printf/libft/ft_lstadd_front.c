/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_lstadd_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aottolin <aottolin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:53:50 by aottolin          #+#    #+#             */
/*   Updated: 2024/01/16 15:04:12 by aottolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_lists **lst, t_lists *new)
{
	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
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
	t_lists	*ato = NULL;
	t_lists	*palabra1;
	t_lists  *palabra2;
	t_lists  *palabra3;

	palabra1 = ft_lstnew("Palabra 1");
	palabra2 = ft_lstnew("Palabra 2");
	palabra3 = ft_lstnew("Palabra 3");

	ft_lstadd_front(&ato, palabra1);
	ft_lstadd_front(&ato, palabra2);
	ft_lstadd_front(&ato, palabra3);
	is_print(ato);

	free(palabra1);
	free(palabra2);
	free(palabra3);

	return (0);
}*/

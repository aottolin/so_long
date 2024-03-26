/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aottolin <aottolin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:53:32 by aottolin          #+#    #+#             */
/*   Updated: 2024/01/17 13:45:20 by aottolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lists	*ft_lstlast(t_lists *lst)
{
	t_lists	*rr;

	if (!lst)
		return (NULL);
	rr = lst;
	while (rr)
	{
		if (rr->next == NULL)
			return (rr);
		else
			rr = rr->next;
	}
	return (NULL);
}
/*
int	main(void)
{
	t_lists	*ato;

	ato = ft_lstnew("NODO1");
	ato->next = ft_lstnew("NODO2");
	ato->next->next = ft_lstnew("NODO3");
	ato->next->next->next = ft_lstnew("NODO4");

	ft_lstlast(ato);
	free(ato);
	return (0);
}*/

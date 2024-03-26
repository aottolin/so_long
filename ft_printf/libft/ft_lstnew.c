/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aottolin <aottolin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:41:07 by aottolin          #+#    #+#             */
/*   Updated: 2024/01/16 12:00:17 by aottolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lists	*ft_lstnew(void *content)
{
	t_lists	*name;

	name = (t_lists *)malloc(sizeof(t_lists));
	if (!name)
		return (NULL);
	if (name)
	{
		name->content = content;
		name->next = NULL;
	}
	return (name);
}
/*
void	print_themother(t_lists *themotherof)
{
	while (themotherof)
	{	
		printf("nodo %s\n", (char *)themotherof->content);
		themotherof = themotherof->next;
	}
}
int	main(void)
{
	t_lists	*ato;

	ato = ft_lstnew("Alex");
	ato->next = ft_lstnew("Thomas");
	ato->next->next = ft_lstnew("Ottolini");
	print_themother(ato);
	return (0);
}*/

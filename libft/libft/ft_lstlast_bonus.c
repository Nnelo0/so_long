/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:31:33 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/24 14:59:54 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int main()
{
	t_list *lst;
	t_list *new_element;
	t_list *last_element;

	lst = NULL;
	
	new_element = ft_lstnew("World!");
	ft_lstadd_front(&lst, new_element);

	new_element = ft_lstnew("hello");
	ft_lstadd_front(&lst, new_element);
	print_list(lst);

	last_element = ft_lstlast(lst);
	
	printf("%s\n",(char *)last_element->content);
	
	while (lst)
	{
		t_list *tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (0);
}*/
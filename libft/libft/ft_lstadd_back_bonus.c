/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:38:42 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/24 15:02:38 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}
/* t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
void	print_list(t_list *lst)
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

	lst = NULL;
	
	new_element = ft_lstnew("world");
	ft_lstadd_back(&lst, new_element);
	print_list(lst);

	new_element = ft_lstnew("hello");
	ft_lstadd_back(&lst, new_element);
	print_list(lst);
	while (lst)
	{
		t_list *tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (0);
} */
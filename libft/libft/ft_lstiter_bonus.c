/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:40:21 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/20 08:40:58 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	if (!lst)
		return ;
	while (lst != NULL)
	{
		(f)(lst->content);
		lst = lst->next;
	}
}
/* void	print_list(void *content)
{
	printf("%s -> ", (char *)content);

}
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int main()
{
	t_list *lst;
	t_list *new_element;

	lst = NULL;
	
	new_element = ft_lstnew("World!");
	ft_lstadd_front(&lst, new_element);
	new_element = ft_lstnew("hello");
	ft_lstadd_front(&lst, new_element);
	
	printf("%s\n", "contenu de la liste");
	ft_lstiter(lst, print_list);
	printf("NULL\n");
	while (lst)
	{
		t_list *tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:26:32 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/24 15:01:03 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
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
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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
	int size;

	lst = NULL;
	
	new_element = ft_lstnew("World!");
	ft_lstadd_front(&lst, new_element);
	print_list(lst);

	new_element = ft_lstnew("hello");
	ft_lstadd_front(&lst, new_element);
	print_list(lst);

	size = ft_lstsize(lst);
	printf("taille : %d\n", size);
	
	while (lst)
	{
		t_list *tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (0);
} */
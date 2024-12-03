/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:40:40 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/20 08:47:24 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone((*lst));
		*lst = temp;
	}
	*lst = NULL;
}

/* t_list	*ft_lstnew(int *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = *content;
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
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_del(void *content)
{
	free(content);
}
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d -> ",lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int main()
{
	t_list *lst;
	t_list *new_element;

	lst = NULL;
	
	new_element = ft_lstnew(ft_strdup("World!"));
	ft_lstadd_front(&lst, new_element);

	new_element = ft_lstnew(ft_strdup("hello"));
	ft_lstadd_front(&lst, new_element);
	printf("%s\n", "avant :");
	print_list(lst);

	ft_lstclear(&lst, ft_del);
	printf("%s\n", "apres :");
	print_list(lst);
	
	
	return (0);
} */
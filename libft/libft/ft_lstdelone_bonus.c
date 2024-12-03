/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:48:31 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/20 08:40:29 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
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
	t_list *delete_element;

	lst = NULL;
	
	new_element = ft_lstnew(ft_strdup("World!"));
	ft_lstadd_front(&lst, new_element);

	new_element = ft_lstnew(ft_strdup("hello"));
	ft_lstadd_front(&lst, new_element);
	printf("%s\n", "avant :");
	print_list(lst);

	delete_element = lst->next;
	ft_lstdelone(delete_element, ft_del);
	lst->next = NULL;
	printf("%s\n", "apres :");
	print_list(lst);
	
	ft_lstdelone(lst, ft_del);
	return (0);
}  */
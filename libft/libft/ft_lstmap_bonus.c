/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:45:57 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/20 08:55:16 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*new;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new);
			return (NULL);
		}
		ft_lstadd_back(&new, new_node);
		lst = lst->next;
	}
	return (new);
}
/* size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
void	*to_upper(void *content)
{
	char	*str;
	int		i;
	char	*new_str;

	i = 0;
	str = (char *)content;
	if (!str)
		return (NULL);

	new_str = malloc(ft_strlen(str) + 1);
	if (!new_str)
		return (NULL);

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			new_str[i] = str[i] - 32; 
		else 
			new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
void	delete_content(void *content)
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
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
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
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = temp;
	}
	*lst = NULL;
}
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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

int main()
{
	t_list *lst;
	t_list *new_element;
	t_list	*new_list;

	lst = NULL;
	
	new_element = ft_lstnew(ft_strdup("World!"));
	ft_lstadd_front(&lst, new_element);
	new_element = ft_lstnew(ft_strdup("hello"));
	ft_lstadd_front(&lst, new_element);
	printf("%s\n", "avant");
	print_list(lst);

	new_list = ft_lstmap(lst, &to_upper, &delete_content);
	printf("%s\n", "apres");
	print_list(new_list);
	ft_lstclear(&lst, &delete_content);
	ft_lstclear(&new_list, &delete_content);
	return (0);
}  */
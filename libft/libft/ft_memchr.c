/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:41:16 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/22 15:43:05 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	while (i < n)
	{
		if (s1[i] == (char)c)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
/*int main()
{
	printf("%s\n", (char *)ft_memchr("hello, world", 'o', 5));
	printf("%s\n", (char *)memchr("hello, world", 'o', 5));
	return 0;
}*/

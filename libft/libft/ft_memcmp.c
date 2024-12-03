/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:51:59 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/22 15:43:38 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	i = 0;
	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while (i < n)
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	return (0);
}
/*
int main() {
	char str1[] = "hello";
	char str2[] = "hella";
	
	printf("Comparaison 1 : %d\n",ft_memcmp(str1, str2, 10)); 
	printf("Comparaison 2 : %d\n",memcmp(str1, str2, 10)); 
	
	return 0;
}*/
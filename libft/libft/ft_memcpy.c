/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:39:27 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/24 09:44:59 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	i = 0;
	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*int main() 
{
	char source[30] = "hello, world";
	char destination[30];
    
	ft_memcpy(destination, source, 5);	
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);
    return 0;
}*/
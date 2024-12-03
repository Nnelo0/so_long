/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:17:54 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/25 08:44:02 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dsa;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	dsa = malloc(nmemb * size);
	if (dsa == NULL)
		return (NULL);
	ft_bzero(dsa, nmemb * size);
	return (dsa);
}
/*void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
int main()
{
	printf("%p\n",ft_calloc(0, 5));
	printf("%p\n",calloc(, 0));
	return 0;
}*/
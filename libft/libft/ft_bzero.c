/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:40:08 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/24 15:40:27 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
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

/*int main()
{
	char test[] = "hello, world";
	
	printf("avant : %s\n", test);
	ft_bzero(test, 5);
	printf("apres : %s", test);
	return (0);
}*/
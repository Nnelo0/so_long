/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:36:03 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/22 15:49:35 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*void to_uppercase(unsigned int index, char *c) {
	(void)index; 
	*c = ft_toupper(*c); 
}
int main() {
	char str[] = "hello world";
	ft_striteri(str, to_uppercase);
	printf("Résultat: %s\n", str);

    return (0);
}*/

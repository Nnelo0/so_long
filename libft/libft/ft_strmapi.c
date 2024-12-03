/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:42:46 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/24 21:19:34 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dsa;

	i = 0;
	dsa = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dsa == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dsa[i] = f(i, s[i]);
		i++;
	}
	dsa[i] = '\0';
	return (dsa);
}

/*size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
char to_upper(unsigned int i, char c) {
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32); 
	return c;
}

int main() {
	char *result = ft_strmapi("hello", to_upper);
	if (result)
		printf("Résultat : %s\n", result);
	free(result);
	return 0;
}*/
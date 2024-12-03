/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:33:51 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/24 21:19:39 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*dsa;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] != '\0' && ft_isset(s1[i], set))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_isset(s1[j - 1], set))
		j--;
	k = j - i;
	dsa = malloc(sizeof(char) * (k + 1));
	if (dsa == NULL)
		return (NULL);
	ft_strncpy(dsa, (char *)s1 + i, k);
	dsa[k] = '\0';
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
int main ()
{
	printf("%s\n", ft_strtrim("aaaaahello worldaaaaaaa", "a"));
	return (0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:26:07 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/19 09:03:20 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(sizeof(char) * (n + 1));
	if (dest == NULL)
		return (NULL);
	while (i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	dup_word(char **dsa, const char *s, char c, int *i)
{
	int	j;

	j = 0;
	while (s[j] != '\0' && s[j] != c)
		j++;
	dsa[*i] = ft_strndup(s, j);
	if (!dsa[*i])
	{
		while (*i > 0)
			free(dsa[--(*i)]);
		free(dsa);
		return (0);
	}
	(*i)++;
	return (1);
}

static int	copy_word(char **dsa, const char *s, char c)
{
	int		i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (!dup_word(dsa, s, c, &i))
				return (0);
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	dsa[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**dsa;

	if (s == NULL)
		return (NULL);
	dsa = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (dsa == NULL)
		return (NULL);
	if (!copy_word(dsa, s, c))
		return (NULL);
	return (dsa);
}

/* int main()
{
	char *s;
	char c;
	char **res;
	int	i;
	
	s = "hello, dsadwa,d,a ,d,,,,,,, dwadwa,,world ,,d test";
	c = ',';
	res = ft_split(s, c);
	i = 0;
	while (res[i] != NULL)
	{
		printf("Segment %d : %s\n", i, res[i]);	
		i++;
	}
    return 0;
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:02:18 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/22 16:35:42 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	d_len = 0;
	s_len = 0;
	while (dst[d_len] != '\0' && d_len < size)
		d_len++;
	while (src[s_len] != '\0')
		s_len++;
	if (size <= d_len)
		return (size + s_len);
	i = 0;
	while (src[i] != '\0' && (d_len + i) < (size - 1))
	{
		dst[d_len + i] = src[i];
		i++;
	}
	if ((d_len + i) < size)
		dst[d_len + i] = '\0';
	return (d_len + s_len);
}
/*int main()
{
	char dest[] = "Hello ";
	char src[] = "World";
	unsigned int size = 5;

	printf("%zu\n", ft_strlcat(dest, src, size));
	return 0;
}*/

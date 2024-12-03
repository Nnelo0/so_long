/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:04:45 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/16 15:46:05 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, &(*s++), 1);
	write(fd, "\n", 1);
}
/*int main()
{
	ft_putendl_fd("hello, world", 0);
	return (0);
}*/
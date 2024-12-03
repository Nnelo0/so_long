/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:34:16 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/03 11:24:24 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static char	*next_line(char *stash)
{
	int		len;
	char	*new_line;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(stash);
	len = 0;
	while (stash[len] != '\0' && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	new_line = malloc(sizeof(char) * ((i - len) + 1));
	if (!new_line)
		return (NULL);
	while (stash[len] != '\0')
	{
		new_line[j++] = stash[len++];
	}
	new_line[j] = '\0';
	free(stash);
	return (new_line);
}

static char	*copy_line(char *stash)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	while (stash[len] != '\n' && stash[len] != '\0')
		len++;
	if (stash[len] == '\n')
		len++;
	if (len == 0)
		return (NULL);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_line(int fd, char *stash)
{
	ssize_t	bytes;
	char	*buf;
	char	*tmp;

	bytes = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), free(stash), NULL);
		buf[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
		if (!stash)
			return (NULL);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_line(fd, stash);
	if (!stash)
		return (NULL);
	line = copy_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = next_line(stash);
	if (!stash[0])
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}

/* int main()
{
	int fd;
	int i = 0;
	char	*next_line;
	fd = open("get_next_line.c", O_RDONLY);
	if (fd == -1)
		return 1;
	while (i < 42)
	{
		next_line = get_next_line(fd);
		printf("%s", next_line);
		free(next_line);
		i++;
	}
	return(0);
} */

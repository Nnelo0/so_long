/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:46:02 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/07 00:12:16 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	read_map(char *filename, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = count_lines(filename);
	fd = open(filename, O_RDONLY);
	data->map = malloc(sizeof(char *) * (i + 1));
	if (!data->map)
		return (1);
	i = 0;
	while (i < count_lines(filename))
	{
		line = get_next_line(fd);
		data->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	data->map[i] = NULL;
	close (fd);
	check_player(data);
	return (0);
}

int	count_carac_line(char *filename)
{
	int		bit;
	int		count;
	int		fd;
	char	c;

	fd = open(filename, O_RDONLY);
	count = 0;
	bit = 1;
	while (bit)
	{
		bit = read(fd, &c, 1);
		if (bit == -1)
			return (ft_printf("Error\nCan't read the files\n"));
		if (c == '\n')
			break ;
		if (bit == 1)
			count++;
	}
	close (fd);
	return (count);
}

int	count_lines(char *filename)
{
	int		bit;
	int		count;
	int		fd;
	char	c;

	fd = open(filename, O_RDONLY);
	count = 0;
	bit = 1;
	while (bit)
	{
		bit = read(fd, &c, 1);
		if (bit == -1)
			return (ft_printf("Error\nCan't read the files\n"));
		if (c == '\n')
			count++;
	}
	count++;
	close (fd);
	return (count);
}

void	load_map(t_data data)
{
	int	x;
	int	y;

	y = 0;
	while (data.map[y])
	{
		x = 0;
		while (data.map[y][x])
		{
			load_map_utils(data, x, y);
			x++;
		}
		y++;
	}
}

int	count_collectibles(char *filename)
{
	int		bit;
	int		count;
	int		fd;
	char	c;

	fd = open(filename, O_RDONLY);
	count = 0;
	bit = 1;
	while (bit)
	{
		bit = read(fd, &c, 1);
		if (bit == -1)
			return (ft_printf("Error\nCan't read the files\n"));
		if (c == 'C')
			count++;
	}
	close (fd);
	return (count);
}

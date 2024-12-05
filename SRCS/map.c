/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:46:02 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/05 16:03:14 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	read_map(char *filename, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = count_lines(filename); //faire gestion d erreur
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

int	count_carac(char *filename)
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
			return (ft_printf("Error\n"));
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
			return (ft_printf("Error\n"));
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
			if (data.map[y][x] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.wall, x * 72, y * 72);
			else if (x * 72 == data.player_x && y * 72 == data.player_y)
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.player, data.player_x, data.player_y);
			else if (data.map[y][x] == '0' || data.map[y][x] == 'P')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.floor, x * 72, y * 72);
			else if (data.map[y][x] == 'C')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.collectible, x * 72, y * 72);
			else if (data.map[y][x] == 'E')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.exit, x * 72, y * 72);
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
			return (ft_printf("Error\n"));
		if (c == 'C')
			count++;
	}
	close (fd);
	return (count);
}

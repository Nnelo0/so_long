/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:46:49 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/07 00:11:11 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	other_carac(int x, int y, t_data *data)
{
	if (data->map[y][x] == 'P')
		return (1);
	if (data->map[y][x] == 'E')
		return (1);
	if (data->map[y][x] == 'C')
		return (1);
	if (data->map[y][x] == '0')
		return (1);
	if (data->map[y][x] == '1')
		return (1);
	if (data->map[y][x] == '\n')
		return (1);
	if (data->map[y][x] == 'S')
		return (1);
	return (0);
}

static void	rectangle_map(t_data *data)
{
	int	first_line;
	int	current_line;
	int	i;

	i = 1;
	first_line = ft_strlen(data->map[0]) - 1;
	if (data->size_x > 26 || data->size_y > 14)
		error(data, "Error\nInvalid size of map\n");
	while (data->map[i] && i != (data->size_y - 1))
	{
		current_line = ft_strlen(data->map[i]) - 1;
		if (current_line != first_line)
			error(data, "Error\nInvalid map\n");
		i++;
	}
	current_line = ft_strlen(data->map[i]);
	if (current_line != first_line)
		error(data, "Error\nInvalid map\n");
}

static void	wall_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[0][x] && x != (data->size_x - 1))
	{
		if (data->map[0][x] != '1')
			error(data, "Error\nInvalid map\n");
		x++;
	}
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][0] != '1')
				error(data, "Error\nInvalid map\n");
			if (data->map[y][data->size_x - 1] != '1')
				error(data, "Error\nInvalid map\n");
			x++;
		}
		y++;
	}
}

static void	correct_map(t_data *data)
{
	int	x;

	x = 0;
	rectangle_map(data);
	wall_map(data);
	while (data->map[data->size_y - 1][x])
	{
		if (data->map[data->size_y - 1][x] != '1')
			error(data, "Error\nInvalid map\n");
		x++;
	}
	check_path(data);
}

void	check_map(t_data *data)
{
	int	x;
	int	y;

	data->count_plr = 0;
	data->count_ext = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (!other_carac(x, y, data))
				error(data, "Error\nInvalid map\n");
			count_carac(data, y, x);
			x++;
		}
		y++;
	}
	if (data->count_plr != 1 || data->count_ext != 1
		|| data->count_collect == 0 || data->count_shred == 0)
		error(data, "Error\nInvalid map\n");
	correct_map(data);
}

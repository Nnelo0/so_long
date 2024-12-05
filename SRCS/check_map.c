/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:46:49 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/05 16:04:44 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	return (0);
}

static void	rectangle_map(t_data *data)
{
	if (data->size_x > 26 || data->size_y > 14)
		error(data);
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
				error(data);
			if (data->map[y][x] == 'P')
				data->count_plr += 1;
			if (data->map[y][x] == 'E')
				data->count_ext += 1;
			x++;
		}
		y++;
	}
	if (data->count_plr != 1 || data->count_ext != 1
		|| data->count_collect == 0)
		error(data);
	rectangle_map(data);
}

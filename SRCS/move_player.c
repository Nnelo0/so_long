/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:44:29 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/05 15:57:33 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_player( t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x * 72;
				data->player_y = y * 72;
			}
			x++;
		}
		y++;
	}
}

static void	exit_game(int new_x, int new_y, t_data *data)
{
	if (data->map[new_y / 72][new_x / 72] == 'E')
	{
		if (data->count_collect == 0)
			close_window(data);
	}
}

static void	collectibles(int new_x, int new_y, t_data *data)
{
	if (data->map[new_y / 72][new_x / 72] == 'C')
	{
		data->count_collect -= 1;
		data->map[new_y / 72][new_x / 72] = '0';
	}
	if (data->count_collect == 0)
	{
		mlx_destroy_image(data->mlx_ptr, data->exit);
		data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "textures/manhole.xpm", &width, &height);
	}
}

void	move_player(int keycode, t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x;
	new_y = data->player_y;
	if (keycode == 'w')
		new_y -= 72;
	if (keycode == 'a')
		new_x -= 72;
	if (keycode == 's')
		new_y += 72;
	if (keycode == 'd')
		new_x += 72;
	collectibles(new_x, new_y, data);
	if (data->map[new_y / 72][new_x / 72] != '1')
	{
		data->player_x = new_x;
		data->player_y = new_y;
		data->count_move += 1;
		ft_printf("move -> %d\n", data->count_move);
	}
	exit_game(new_x, new_y, data);
}

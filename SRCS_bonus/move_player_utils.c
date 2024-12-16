/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:22:29 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/10 11:22:33 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	display_move_counter(t_data *data)
{
	char	*count_move;

	count_move = ft_itoa(data->count_move);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 30, 0x000000, "Moves :");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 31, 0x000000, count_move);
	free(count_move);
}

void	count_carac(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'P')
		data->count_plr += 1;
	if (data->map[y][x] == 'E')
		data->count_ext += 1;
}

void	animation_player(int keycode, t_data *data, int new_x, int new_y)
{
	int	width;
	int	height;

	if (keycode == 'a')
	{
		mlx_destroy_image(data->mlx_ptr, data->player);
		data->player = mlx_xpm_file_to_image(data->mlx_ptr,
				"textures/purple_turtle_90.xpm", &width, &height);
	}
	if (keycode == 'd')
	{
		mlx_destroy_image(data->mlx_ptr, data->player);
		data->player = mlx_xpm_file_to_image(data->mlx_ptr,
				"textures/purple_turtle.xpm", &width, &height);
	}
	data->player_x = new_x;
	data->player_y = new_y;
}

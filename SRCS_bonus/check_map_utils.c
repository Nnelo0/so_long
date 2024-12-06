/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:32:46 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/07 00:11:05 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	load_map_utils(t_data data, int x, int y)
{
	if (data.map[y][x] == '1')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.wall, x * 72, y * 72);
	else if (x * 72 == data.player_x && y * 72 == data.player_y)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.player,
			data.player_x, data.player_y);
	else if (data.map[y][x] == '0' || data.map[y][x] == 'P')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.floor, x * 72, y * 72);
	else if (data.map[y][x] == 'C')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.collectible, x * 72, y * 72);
	else if (data.map[y][x] == 'E')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.exit, x * 72, y * 72);
	else if (data.map[y][x] == 'S')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.shredder, x * 72, y * 72);
}

static void	flood_fill(char **map, int x, int y, int *valid)
{
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'S')
		return ;
	if (map[y][x] == 'C' || map [y][x] == 'E')
		(*valid)--;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, valid);
	flood_fill(map, x - 1, y, valid);
	flood_fill(map, x, y + 1, valid);
	flood_fill(map, x, y - 1, valid);
}

void	check_path(t_data *data)
{
	int		valid;
	int		i;
	char	**map_copy;

	i = 0;
	valid = data->count_collect + data->count_ext;
	map_copy = malloc(sizeof(char *) * (data->size_y + 1));
	if (!map_copy)
		error(data, "Error\nmalloc error\n");
	while (data->map[i])
	{
		map_copy[i] = ft_strdup(data->map[i]);
		i++;
	}
	map_copy[i] = NULL;
	flood_fill(map_copy, data->player_x / 72, data->player_y / 72, &valid);
	i = 0;
	while (map_copy[i])
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
	if (valid != 0)
		error(data, "Error\nInvalid path in map\n");
}

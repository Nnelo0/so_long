/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:01:29 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/03 13:35:57 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	return (0);
}

void	load_map(t_data *data)
{
	int width;
	int height;

	data->wall_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/wall.xpm", &width, &height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall_ptr, 0, 0);
}

int	open_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 900, 900, "so_long");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 1);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	load_map(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

void	initialize_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
}

int	main(int argc, char **argv)
{
	t_data data;
	
	initialize_data(&data);
	open_window(&data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:01:29 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/16 08:55:48 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	load_images(t_data *data)
{
	int	width;
	int	height;

	data->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/wall2.xpm", &width, &height);
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/road.xpm", &width, &height);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/purple_turtle.xpm", &width, &height);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/manhole_close.xpm", &width, &height);
	data->collectible = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/pizza.xpm", &width, &height);
	data->shredder = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/shredder.xpm", &width, &height);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	if (keycode == 'w')
		move_player('w', data);
	else if (keycode == 'a')
		move_player('a', data);
	else if (keycode == 's')
		move_player('s', data);
	else if (keycode == 'd')
		move_player('d', data);
	return (0);
}

static int	loop(t_data *data)
{
	load_map(*data);
	display_move_counter(data);
	return (0);
}

int	open_window(t_data *data, char **argv)
{
	read_map(argv[1], data);
	data->count_collect = count_collectibles(argv[1]);
	data->size_x = count_carac_line(argv[1]);
	data->size_y = count_lines(argv[1]);
	check_map(data);
	data->count_move = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, (72 * data->size_x),
			(72 * data->size_y), "so_long");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 1);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx_ptr, loop, data);
	load_images(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	if (argc != 2)
		return (ft_printf("Error\nInvalid number of argument\n"));
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (ft_printf("Error\nInvalid argument\n"));
		close (fd);
		if (ber(argv))
			exit(ft_printf("Error\nInvalid argument\n"));
		open_window(&data, argv);
	}
	return (0);
}

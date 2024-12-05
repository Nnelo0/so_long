/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:01:29 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/05 13:16:22 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_data *data)
{
	int i;

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->floor);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->player);
	mlx_destroy_image(data->mlx_ptr, data->collectible);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	while (data->map[i])
    {
        free(data->map[i]);
        i++;
    }
	free(data->map);
	exit(0);
	return (0);
}

int count_carac(char *filename)
{
    int    	bit;
    int     count;
	int		fd;
	char	c;

	fd = open(filename, O_RDONLY);
	count = 0;
	bit = 1;
	while (bit)
	{
		bit = read(fd, &c, 1);
		if (bit == -1)
			return(ft_printf("Error\n"));
		if (c == '\n')
			break;
		if (bit == 1)
			count++;
	}
	close (fd);
	return (count);
}

int count_lines(char *filename)
{
    int    	bit;
    int     count;
	int		fd;
	char	c;

	fd = open(filename, O_RDONLY);
	count = 0;
	bit = 1;
	while (bit)
	{
		bit = read(fd, &c, 1);
		if (bit == -1)
			return(ft_printf("Error\n"));
		if (c == '\n')
			count++;
	}
	count++;
	close (fd);
	return (count);
}

int	read_map(char *filename, t_data *data)
{
    int     i;
	int		fd;
	char	*line;

	/* faire gestion d'erreur */
	i = count_lines(filename);
	fd = open(filename, O_RDONLY);
	data->map = malloc(sizeof(char *) * (i + 1));
	if (!data->map)
		return (1);
	i  = 0;
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

void	load_map(t_data data)
{
	int	x;
	int y;

	y = 0;
	while (data.map[y])
	{
		x = 0;
		while (data.map[y][x])
		{
			if (data.map[y][x] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.wall, x * TILES_SIZE, y * TILES_SIZE);
			else if(x * 72 == data.player_x && y * 72 == data.player_y)
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.player, data.player_x, data.player_y);
			else if(data.map[y][x] == '0' || data.map[y][x] == 'P')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.floor, x * TILES_SIZE, y * TILES_SIZE);
			else if(data.map[y][x] == 'C')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.collectible, x * TILES_SIZE, y * TILES_SIZE);
			else if(data.map[y][x] == 'E')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.exit, x * TILES_SIZE, y * TILES_SIZE);
			x++;
		}
		y++;
	}
}

void	load_images(t_data *data)
{
	int width;
	int height;

	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "images/wall2.xpm", &width, &height);
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr, "images/road.xpm", &width, &height);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, "images/purple_turtle.xpm", &width, &height);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "images/manhole.xpm", &width, &height);
	data->collectible = mlx_xpm_file_to_image(data->mlx_ptr, "images/pizza.xpm", &width, &height);
}

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
int count_collectibles(char *filename)
{
    int    	bit;
    int     count;
	int		fd;
	char	c;

	fd = open(filename, O_RDONLY);
	count = 0;
	bit = 1;
	while (bit)
	{
		bit = read(fd, &c, 1);
		if (bit == -1)
			return(ft_printf("Error\n"));
		if (c == 'C')
			count++;
	}
	close (fd);
	return (count);
}
void	exit_game(int new_x, int new_y ,t_data *data)
{
	if (data->map[new_y / 72][new_x / 72] == 'E')
	{
		if (data->count_collect == 0)
			close_window(data);
	}
}

void	collectibles(int new_x, int new_y ,t_data *data)
{
	if (data->map[new_y / 72][new_x / 72] == 'C')
	{
		data->count_collect -= 1;
		data->map[new_y / 72][new_x / 72] = '0';
	}
}
void	move_player(int keycode, t_data *data)
{
	int new_x;
	int new_y;

	new_x = data->player_x;
	new_y = data->player_y;
	
	if (keycode == 'w')
		new_y -= 72;
	if (keycode == 'a')
		new_x-= 72;
	if (keycode == 's')
		new_y += 72;
	if (keycode == 'd')
		new_x += 72;
	collectibles(new_x, new_y, data);
	exit_game(new_x, new_y, data);
	if (data->map[new_y / 72][new_x / 72] != '1')
	{
		data->player_x = new_x;
		data->player_y = new_y;
		data->count_move += 1;
		ft_printf("move -> %d\n", data->count_move);
	}
}

int key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 'w')
		move_player('w' , data);
	else if (keycode == 'a')
		move_player('a', data);
	else if (keycode == 's')
		move_player('s', data);
	else if (keycode == 'd')
		move_player('d', data);
	return (0);
}

int loop(t_data *data)
{
	load_map(*data);
	return (0);
}

int	open_window(t_data *data, char **argv)
{	
	data->count_move = 0;
	data->count_collect = count_collectibles(argv[1]);
	read_map(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, (72 * count_carac(argv[1])), (72 * count_lines(argv[1])), "so_long");
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
	t_data data;

	if (argc != 2)
		return(ft_printf("Error\n"));
	if (argc == 2)
	{
		open_window(&data, argv);
	}
	return (0);
}

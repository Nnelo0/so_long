/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:01:29 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/04 12:54:47 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_data *data)
{
	int i;

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->floor_ptr);
	mlx_destroy_image(data->mlx_ptr, data->wall_ptr);
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

	/*faire gestion d'erreur */
	i = count_lines(filename);
	fd = open(filename, O_RDONLY);
	data->map = malloc(sizeof(char *) * (i + 1));
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
	return (0);
}

void	load_map(t_data data)
{
	int	x;
	int y;

	x = 0;
	while (data.map[x])
	{
		y = 0;
		while (data.map[x][y])
		{
			if (data.map[x][y] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.wall_ptr, y * TILES_HEIGHT, x * TILES_HEIGHT);
			else if(data.map[x][y] == '0')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.floor_ptr, y * TILES_HEIGHT, x * TILES_HEIGHT);
			y++;
		}
		x++;
	}
}
void	load_images(t_data *data)
{
	int width;
	int height;

	data->wall_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/wall.xpm", &width, &height);
	data->floor_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/floor.xpm", &width, &height);
}
int key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	return (0);
}

int	open_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 900, 900, "so_long");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 1);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	load_images(data);
	load_map(*data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;
	//int i = 0;
	if (argc != 2)
		return(ft_printf("Error\n"));
	if (argc == 2)
	{
		read_map(argv[1], &data);
		open_window(&data);
		
/* 	while (data.map[i])
    {
        ft_printf("%s", data.map[i]);
        free(data.map[i]);
        i++;
    }
    free(data.map); */
	}
	return (0);
}

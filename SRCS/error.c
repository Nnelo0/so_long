/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:48:45 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/06 19:59:03 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_data *data)
{
	int	i;

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

void	error(t_data *data, char *str)
{
	int	i;

	i = 0;
	(void)data;
	write(2, str, ft_strlen(str));
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	exit(1);
}

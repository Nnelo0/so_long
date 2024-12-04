/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:00:19 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/04 11:25:00 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft/libft.h"
# include "libft/printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

# define TILES_HEIGHT 72

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_ptr;
	void	*floor_ptr;
	char		**map;
}				t_data;

int		close_window(t_data *data);
int 	key_hook(int keycode, t_data *data);
int		open_window(t_data *data);
void	initialize_data(char *argv, t_data *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:00:19 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/05 13:07:36 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft/libft.h"
# include "libft/printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

# define TILES_SIZE 72

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall;
	void	*floor;
	void	*player;
	int		player_x;
	int		player_y;
	void	*exit;
	void	*collectible;
	int		count_collect;
	char		**map;
	int		count_move;
}				t_data;

int		close_window(t_data *data);
int 	key_hook(int keycode, t_data *data);
int		open_window(t_data *data, char **argv);
void	initialize_data(char *argv, t_data *data);
void	check_player(t_data *data);

#endif
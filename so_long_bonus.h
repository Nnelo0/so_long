/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:00:19 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/06 23:56:05 by nnelo            ###   ########.fr       */
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
	int		count_plr;
	int		player_x;
	int		player_y;
	void	*exit;
	int		count_ext;
	void	*collectible;
	int		count_collect;
	char	**map;
	int		count_move;
	int		size_x;
	int		size_y;
	void	*shredder;
	int		count_shred;
}				t_data;

int		open_window(t_data *data, char **argv);
int		key_hook(int keycode, t_data *data);
void	move_player(int keycode, t_data *data);
int		count_collectibles(char *filename);
void	check_player( t_data *data);
void	check_map(t_data *data);
void	error(t_data *data, char *str);
void	load_images(t_data *data);
void	load_map(t_data data);
void	load_map_utils(t_data data, int x, int y);
int		read_map(char *filename, t_data *data);
int		count_lines(char *filename);
int		count_carac_line(char *filename);
int		close_window(t_data *data);
void	check_path(t_data *data);
void	display_move_counter(t_data *data);
void	count_carac(t_data *data, int y, int x);
void	animation_player(int keycode, t_data *data, int new_x, int new_y);

#endif
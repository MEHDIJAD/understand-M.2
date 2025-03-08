/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:36:13 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 18:05:07 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define BUFFER_SIZE 1
# define IMAGE_SIZE 32
# define SIZE_MAX 18446744073709551615ULL
# define OPEN_MAX 1024

# include "/home/eel-garo/include/mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_enemy
{
	int	x;
	int	y;
	int	direction;
}	t_enemy;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_hero;
	void	*img_wall;
	void	*img_floor;
	void	*img_collact;
	void	*img_exit;
	void	*img_exit_open;
	void	*img_enemy;
	int		img_widht;
	int		img_height;
	char	**ptr;
	t_enemy	*enemies;
	size_t	enemy_count;
	int		x;
	int		y;
	char	*relative_path_hero;
	char	*relative_path_wall;
	char	*relative_path_floor;
	char	*relative_path_collact;
	char	*relative_path_exit;
	char	*relative_path_enemy;
	char	*relative_path_exit_open;
	int		x_p;
	int		y_p;
	int		cl;
}	t_data;

typedef struct s_param
{
	bool	player;
	bool	exit;
	bool	collact;
	bool	wall;
	bool	space;
	bool	enemy;
}	t_param;

typedef struct s_position
{
	int	old_x;
	int	old_y;
	int	new_x;
	int	new_y;
}	t_position;

typedef struct s_exit
{
	int	x;
	int	y;	
}	t_exit;

char	*get_next_line(int fd);
int		ft_get_map(char *str, t_data *data);
int		ft_get_map_dimention(t_data *data);
int		ft_get_img_data(t_data *data);
void	ft_drow_map(t_data *data);
int		ft_first_move(int keycode, t_data *data);
void	ft_get_player_position(t_data *data);
int		ft_valid_map(t_data *data);
void	ft_cleanup_game(t_data *data);
void	ft_free_map(char **ptr);
int		ft_exit(t_data *data);
int		ft_surrounded_by_walls_check(t_data *data);
int		ft_check_components(t_data *data);
int		small_check(t_data *data);
int		ft_rectangular_check(t_data *data);
int		ft_min_components(t_data *data);
int		ft_check_file_map(char *map_ber);
void	ft_puterror(int error_code);
int		ft_playable_map(t_data *data);
void	ft_put_image(t_data *data, int i, int j, char c);
void	ft_init_data(t_data *data);
size_t	ft_enemy_count(t_data *data);
int		ft_moving_enemy(t_data *data);
int		ft_get_enemy_positions(t_data *data);
int		ft_count_collectibles(t_data *data);
int		put_move(t_data *data, int new_y, int new_x, int *movement_count);
int		ft_put_open_door(t_data *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:31:24 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/23 13:00:06 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "./../mlx_linux/mlx.h"
# include "./../mlx_linux/mlx_int.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_data
{
	int		width;
	int		height;
	char	*path;
	void	*img;

}				t_data;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	char	**coin_map;
	char	**exit_map;

}				t_map;

typedef struct s_object
{
	int		x;
	int		y;
	int		nb;
	int		dir;
	int		width;
	int		height;
	char	*path;
	void	*img;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
}			t_object;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_data		screen;
	t_data		background;
	t_object	player;
	t_object	coin;
	t_object	exit;
	t_object	wall;
	t_object	hole;
}				t_vars;

// -------------- MAIN -------------- //
int			main(int argc, char **argv);

// ----------- ARGS_CHECK ----------- //
void		check_args(int argc, char **argv);

// -------------- EXIT -------------- //
void		ft_exit(char *msg, int status);
void		mlx_error(t_vars *vars);
void		mlx_exit(t_vars *vars, char *msg, int status);
void		mlx_hook_exit(t_vars *vars);

// -------------- FREE -------------- //
void		ft_free_map(t_vars *vars);
void		mlx_free(t_vars *vars);

// ----------- FLOOD_FILL ----------- //
int			ft_flood_fill_coin(t_vars *vars, char **map, int x, int y);
int			ft_flood_fill_exit(t_vars *vars, char **map, int x, int y);
// --------------- GNL -------------- //
char		*get_next_line(int fd);

// ------------- FT_PUT ------------- //
void		ft_putstr(char *str);
void		ft_putnbr(int n);
void		ft_putmoves(t_vars *vars);

// ------------ FT_SPLIT ------------ //
char		**ft_split(char const *s, char c);

// ----------- FT_STRJOIN ----------- //
char		*ft_strjoin(char *s1, char *s2);

// ------------ FT_UTILS ------------ //
size_t		ft_len(int n);
char		*ft_itoa(int n);
int			ft_strlen(const char *str);
int			ft_compare(char c, char c1);
char		*ft_strchr(const char *string, int c);
char		*ft_calloc(size_t nmemb, size_t size);
int			ft_count_word(char const *s, char c);

// ---------- COLLECTIBLES ---------- //
void		check_collectible(t_vars *vars);

// ------------ GAME_EXIT ----------- //
void		check_exit(t_vars *vars, int direction);
int			check_stand_exit(t_vars *vars);
int			check_black_hole(t_vars *vars, int direction);

// -------------- MOVES ------------- //
void		move_up(t_vars *vars);
void		move_down(t_vars *vars);
void		move_right(t_vars *vars);
void		move_left(t_vars *vars);

// ------------- POSITION ----------- //
int			get_position_x(t_vars *vars, char c);
int			get_position_y(t_vars *vars, char c);

// ------------ MAP_CHECK ----------- //
void		check_map_shape(t_vars *vars);
void		check_map_walls(t_vars *vars);
void		check_map_path(t_vars *vars);
void		check_map_letters(t_vars *vars);
void		check_map_player(t_vars *vars);
void		check_map_exit(t_vars *vars);
void		check_map(t_vars *vars);

// ------------ MAP_OPEN ------------ //
void		check_path(char *path);
void		check_ext(char *path);
void		open_map(t_vars *vars, char *path);
void		read_map(t_vars *vars, char *path);
void		count_objects(t_vars *vars);

// ------------ MLX_INIT ------------ //
void		mlx_initialize_win(t_vars *vars);
void		mlx_initialize_img(t_vars *vars);
void		mlx_initialize_player(t_vars *vars);
void		mlx_initialize_exit(t_vars *vars);
void		mlx_initialize_objects(t_vars *vars);

// ------------- MLX_RUN ------------ //
int			key_press(int keycode, t_vars *vars);
int			render_frame(t_vars *vars);

#endif

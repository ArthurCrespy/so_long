/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:31:24 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/21 22:30:34 by acrespy          ###   ########.fr       */
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

}				t_map;

typedef struct s_object
{
	int		x;
	int		y;
	int		width;
	int		height;
	char	*path;
	void	*img;
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
}				t_vars;

void		check_map(t_vars *vars);
void		open_map(t_vars *vars, char *path);

void		mlx_initialize_win(t_vars *vars);
void		mlx_initialize_img(t_vars *vars);

int			key_press(int keycode, t_vars *vars);
int			render_frame(t_vars *vars);

void		mlx_free(t_vars *vars);
void		mlx_error(t_vars *vars);
void		mlx_exit(t_vars *vars);

void		move_up(t_vars *vars);
void		move_down(t_vars *vars);
void		move_right(t_vars *vars);
void		move_left(t_vars *vars);

void		ft_exit(char *s, int status);

char		*get_next_line(int fd);
char		**ft_split(char const *s, char c);

int			ft_strlen(const char *str);
char		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strchr(const char *string, int c);
char		*ft_strjoin(char *s1, char *s2);

#endif

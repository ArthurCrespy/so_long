/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:31:24 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/09 06:43:05 by acrespy          ###   ########.fr       */
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

typedef struct s_object
{
	int		x;
	int		y;
	int		width;
	int		height;
	char	*path;
	void	*img;
}			t_object;

typedef struct s_data
{
	int		width;
	int		height;
	char	*path;
	void	*img;

}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	char 		**map;
	t_data		background;
	t_object	player;
	t_object	coin;
	t_object	exit;
	t_object	wall;
}				t_vars;

int     ft_strlen(const char *str);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *string, int c);
char	*ft_strjoin(char  *s1, char  *s2);

#endif

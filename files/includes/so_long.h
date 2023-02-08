/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:31:24 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/06 14:33:05 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./../mlx_linux/mlx.h"
# include "./../mlx_linux/mlx_int.h"

typedef struct s_objects
{
	void                *img;
	struct s_objects    *next;
}                       t_objects;

typedef struct s_player
{
	int		x;
	int		y;
	int 	width;
	int 	height;
	char 	*path;
	void    *img;
}				t_player;

typedef struct s_coin
{
	int		x;
	int		y;
	int 	width;
	int 	height;
	char 	*path;
	void    *img;
}				t_coin;

typedef struct s_data
{
	int 	width;
	int 	height;
	char 	*path;
	void	*img;

}				t_data;

typedef struct s_vars
{
	void	    *mlx;
	void	    *mlx_win;
	t_data	    background;
	t_player    player;
	t_coin      coin;
}				t_vars;

#endif

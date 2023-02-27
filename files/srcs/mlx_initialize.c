/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:11:48 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/23 12:56:10 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mlx_initialize_win(t_vars *vars)
{
	vars->mlx = NULL;
	vars->mlx_win = NULL;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		mlx_error(vars);
	mlx_get_screen_size(vars->mlx, &vars->screen.width, &vars->screen.height);
	if (vars->map.width <= vars->screen.width
		&& vars->map.height <= vars->screen.height)
		vars->mlx_win = mlx_new_window(vars->mlx, vars->map.width,
				vars->map.height, "So Long!");
	else
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		ft_exit("Error: Map is too big for the screen\n", 1);
	}
	if (!vars->mlx_win)
		mlx_error(vars);
}

void	mlx_initialize_img(t_vars *vars)
{
	vars->background.img = NULL;
	vars->wall.img = NULL;
	vars->coin.img = NULL;
	vars->hole.img = NULL;
	vars->exit.img = NULL;
	vars->exit.img1 = NULL;
	vars->player.img = NULL;
	vars->player.img1 = NULL;
	vars->player.img2 = NULL;
	vars->player.img3 = NULL;
	vars->player.img4 = NULL;
	vars->player.img5 = NULL;
	mlx_initialize_objects(vars);
	mlx_initialize_exit(vars);
	mlx_initialize_player(vars);
}

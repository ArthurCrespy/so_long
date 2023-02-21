/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:11:48 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/21 22:15:38 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mlx_initialize_win(t_vars *vars)
{
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
		mlx_free(vars);
		ft_exit("Error: Map is too big for the screen\n", 1);
	}
	if (!vars->mlx_win)
		mlx_error(vars);
}

void	mlx_initialize_img(t_vars *vars)
{
	vars->background.path = "./../assets/background.xpm";
	vars->background.img = mlx_xpm_file_to_image(vars->mlx,
			vars->background.path,
			&vars->background.width, &vars->background.height);
	if (!vars->background.img)
		mlx_error(vars);
	vars->wall.path = "./../assets/wall.xpm";
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, vars->wall.path,
			&vars->wall.width, &vars->wall.height);
	if (!vars->wall.img)
		mlx_error(vars);
	vars->player.path = "./../assets/sly_cooper.xpm";
	vars->player.img = mlx_xpm_file_to_image(vars->mlx, vars->player.path,
			&vars->player.width, &vars->player.height);
	if (!vars->player.img)
		mlx_error(vars);
	vars->coin.path = "./../assets/coin.xpm";
	vars->coin.img = mlx_xpm_file_to_image(vars->mlx, vars->coin.path,
			&vars->coin.width, &vars->coin.height);
	if (!vars->coin.img)
		mlx_error(vars);
	vars->exit.path = "./../assets/exit.xpm";
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, vars->exit.path,
			&vars->exit.width, &vars->exit.height);
	if (!vars->exit.img)
		mlx_error(vars);
}

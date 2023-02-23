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

void	mlx_initialize_player_img(t_vars *vars)
{
	vars->player.path = "./../assets/player.xpm";
	vars->player.img = mlx_xpm_file_to_image(vars->mlx, vars->player.path,
			&vars->player.width, &vars->player.height);
	if (!vars->player.img)
		mlx_error(vars);
	vars->player.path1 = "./../assets/player1.xpm";
	vars->player.img1 = mlx_xpm_file_to_image(vars->mlx, vars->player.path1,
			&vars->player.width, &vars->player.height);
	if (!vars->player.img1)
		mlx_error(vars);
}

void	mlx_initialize_player(t_vars *vars)
{
	int	i_row;
	int	i_col;

	i_row = 0;
	vars->player.nb = 0;
	vars->player.nb1 = 1;
	while (vars->map.map[i_row])
	{
		i_col = 0;
		while (vars->map.map[i_row][i_col])
		{
			if (vars->map.map[i_row][i_col] == 'P')
			{
				vars->player.x = i_col * 64;
				vars->player.y = i_row * 64;
			}
			i_col++;
		}
		i_row++;
	}
	mlx_initialize_player_img(vars);
}

void	mlx_initialize_exit(t_vars *vars)
{
	vars->exit.path = "./../assets/exit.xpm";
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, vars->exit.path,
			&vars->exit.width, &vars->exit.height);
	if (!vars->exit.img)
		mlx_error(vars);
	vars->exit.path1 = "./../assets/exit1.xpm";
	vars->exit.img1 = mlx_xpm_file_to_image(vars->mlx, vars->exit.path1,
			&vars->exit.width, &vars->exit.height);
	if (!vars->exit.img1)
		mlx_error(vars);
}

void	mlx_initialize_img(t_vars *vars)
{
	mlx_initialize_player(vars);
	mlx_initialize_exit(vars);
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
	vars->coin.path = "./../assets/coin.xpm";
	vars->coin.img = mlx_xpm_file_to_image(vars->mlx, vars->coin.path,
			&vars->coin.width, &vars->coin.height);
	if (!vars->coin.img)
		mlx_error(vars);
	vars->hole.path = "./../assets/hole.xpm";
	vars->hole.img = mlx_xpm_file_to_image(vars->mlx, vars->hole.path,
			&vars->hole.width, &vars->hole.height);
	if (!vars->hole.img)
		mlx_error(vars);
}

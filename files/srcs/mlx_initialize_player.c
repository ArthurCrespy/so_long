/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialize_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:11:48 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/23 12:56:10 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

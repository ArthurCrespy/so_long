/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialize_objects.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:11:48 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/23 12:56:10 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mlx_initialize_objects(t_vars *vars)
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
	vars->coin.path = "./../assets/coin.xpm";
	vars->coin.img = mlx_xpm_file_to_image(vars->mlx, vars->coin.path,
			&vars->coin.width, &vars->coin.height);
	if (!vars->coin.img)
		mlx_error(vars);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialize_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:11:48 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/23 12:56:10 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mlx_initialize_exit(t_vars *vars)
{
	vars->hole.path = "./../assets/hole.xpm";
	vars->hole.img = mlx_xpm_file_to_image(vars->mlx, vars->hole.path,
			&vars->hole.width, &vars->hole.height);
	if (!vars->hole.img)
		mlx_error(vars);
	vars->exit.path = "./../assets/exit.xpm";
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, vars->exit.path,
			&vars->exit.width, &vars->exit.height);
	if (!vars->exit.img)
		mlx_error(vars);
	vars->exit.path = "./../assets/exit1.xpm";
	vars->exit.img1 = mlx_xpm_file_to_image(vars->mlx, vars->exit.path,
			&vars->exit.width, &vars->exit.height);
	if (!vars->exit.img1)
		mlx_error(vars);
}

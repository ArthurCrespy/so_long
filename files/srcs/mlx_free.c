/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:16:08 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/21 22:16:26 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mlx_free(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map.map[i])
		free(vars->map.map[i++]);
	if (vars->map.map)
		free(vars->map.map);
	if (vars->background.img)
		mlx_destroy_image(vars->mlx, vars->background.img);
	if (vars->player.img)
		mlx_destroy_image(vars->mlx, vars->player.img);
	if (vars->coin.img)
		mlx_destroy_image(vars->mlx, vars->coin.img);
	if (vars->wall.img)
		mlx_destroy_image(vars->mlx, vars->wall.img);
	if (vars->exit.img)
		mlx_destroy_image(vars->mlx, vars->exit.img);
	if (vars->mlx_win)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	if (vars->mlx_win)
		mlx_destroy_display(vars->mlx);
	if (vars->mlx)
		free(vars->mlx);
}

void	mlx_exit(t_vars *vars)
{
	mlx_free(vars);
	exit(0);
}

void	mlx_error(t_vars *vars)
{
	mlx_free(vars);
	ft_exit("Error: Something went wrong with MiniLibX\n", 1);
}

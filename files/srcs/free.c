/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:16:08 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/22 21:15:02 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map.map[i])
		free(vars->map.map[i++]);
	if (vars->map.map)
		free(vars->map.map);
}

void	mlx_free(t_vars *vars)
{
	ft_free_map(vars);
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

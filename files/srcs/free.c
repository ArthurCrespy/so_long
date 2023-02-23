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
	i = 0;
	while (vars->map.coin_map[i])
		free(vars->map.coin_map[i++]);
	if (vars->map.coin_map)
		free(vars->map.coin_map);
	i = 0;
	while (vars->map.exit_map[i])
		free(vars->map.exit_map[i++]);
	if (vars->map.exit_map)
		free(vars->map.exit_map);
}

void	mlx_free_mlx(t_vars *vars)
{
	if (vars->mlx_win)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	if (vars->mlx_win)
		mlx_destroy_display(vars->mlx);
	if (vars->mlx)
		free(vars->mlx);
}

void	mlx_free(t_vars *vars)
{
	ft_free_map(vars);
	if (vars->background.img)
		mlx_destroy_image(vars->mlx, vars->background.img);
	if (vars->player.img)
		mlx_destroy_image(vars->mlx, vars->player.img);
	if (vars->player.img1)
		mlx_destroy_image(vars->mlx, vars->player.img1);
	if (vars->player.img2)
		mlx_destroy_image(vars->mlx, vars->player.img2);
	if (vars->player.img3)
		mlx_destroy_image(vars->mlx, vars->player.img3);
	if (vars->coin.img)
		mlx_destroy_image(vars->mlx, vars->coin.img);
	if (vars->wall.img)
		mlx_destroy_image(vars->mlx, vars->wall.img);
	if (vars->exit.img)
		mlx_destroy_image(vars->mlx, vars->exit.img1);
	if (vars->exit.img1)
		mlx_destroy_image(vars->mlx, vars->exit.img);
	if (vars->hole.img)
		mlx_destroy_image(vars->mlx, vars->hole.img);
	mlx_free_mlx(vars);
}


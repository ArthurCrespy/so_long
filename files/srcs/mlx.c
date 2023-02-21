/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:23:44 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/21 22:26:21 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int keycode, t_vars *vars)
{
	printf("key pressed %d\n", keycode);
	if (keycode == 65307)
		mlx_exit(vars);
	if (keycode == 65361)
		move_left(vars);
	if (keycode == 65362)
		move_up(vars);
	if (keycode == 65363)
		move_right(vars);
	if (keycode == 65364)
		move_down(vars);
	return (0);
}

int	render_frame(t_vars *vars)
{
	int	i_col;
	int	i_row;

	i_col = 0;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->background.img, 0, 0);
	while (vars->map.map[i_col])
	{
		i_row = 0;
		while (vars->map.map[i_col][i_row])
		{
			if (vars->map.map[i_col][i_row] == '1')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->wall.img, i_row * 64, i_col * 64);
			else if (vars->map.map[i_col][i_row] == 'P')
			{
				vars->player.x = i_row * 64;
				vars->player.y = i_col * 64;
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->player.img, i_row * 64, i_col * 64);
			}
			else if (vars->map.map[i_col][i_row] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->coin.img, i_row * 64, i_col * 64);
			else if (vars->map.map[i_col][i_row] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->exit.img, i_row * 64, i_col * 64);
			i_row++;
		}
		i_col++;
	}
	usleep(100000 / 120);
	return (0);
}

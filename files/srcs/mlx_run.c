/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:23:44 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/23 12:58:40 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_exit(vars, NULL, 0);
	if (keycode == 65361 || keycode == 97)
		move_left(vars);
	if (keycode == 65362 || keycode == 119)
		move_up(vars);
	if (keycode == 65363 || keycode == 100)
		move_right(vars);
	if (keycode == 65364 || keycode == 115)
		move_down(vars);
	return (0);
}

void	render_collectibles(t_vars *vars)
{
	int	i_col;
	int	i_row;

	i_col = 0;
	while (vars->map.map[i_col])
	{
		i_row = 0;
		while (vars->map.map[i_col][i_row])
		{
			if (vars->map.map[i_col][i_row] == 'X')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->hole.img, i_row * 64, i_col * 64);
			else if (vars->map.map[i_col][i_row] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->coin.img, i_row * 64, i_col * 64);
			else if (vars->coin.nb != 0 && vars->map.map[i_col][i_row] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->exit.img, i_row * 64, i_col * 64);
			else if (vars->coin.nb == 0 && vars->map.map[i_col][i_row] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->exit.img1, i_row * 64, i_col * 64);
			i_row++;
		}
		i_col++;
	}
}

void	render_walls(t_vars *vars)
{
	int	i_col;
	int	i_row;

	i_col = 0;
	while (vars->map.map[i_col])
	{
		i_row = 0;
		while (vars->map.map[i_col][i_row])
		{
			if (vars->map.map[i_col][i_row] == '1')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->wall.img, i_row * 64, i_col * 64);
			i_row++;
		}
		i_col++;
	}
}

void	render_player(t_vars *vars)
{
	if (vars->player.nb1 == -1)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img, vars->player.x, vars->player.y);
	if (vars->player.nb1 == 1)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img1, vars->player.x, vars->player.y);
}

int	render_frame(t_vars *vars)
{
	char	*count;

	count = ft_itoa(vars->player.nb);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->background.img, 0, 0);
	render_walls(vars);
	render_collectibles(vars);
	render_player(vars);
	mlx_string_put(vars->mlx, vars->mlx_win, 10, 10, 0xFFFFFF, "NB of moves:");
	mlx_string_put(vars->mlx, vars->mlx_win, 150, 10, 0xFFFFFF, count);
	free(count);
	usleep(100000 / 60);
	return (0);
}

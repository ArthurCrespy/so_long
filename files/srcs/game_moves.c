/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:16:34 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/23 12:56:59 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_collision(t_vars *vars, int direction)
{
	int	i_col;
	int	i_row;

	i_col = vars->player.y / 64;
	i_row = vars->player.x / 64;
	if (direction == 1 && vars->map.map[i_col - 1][i_row] == '1')
		return (1);
	if (direction == 2 && vars->map.map[i_col + 1][i_row] == '1')
		return (1);
	if (direction == 3 && vars->map.map[i_col][i_row - 1] == '1')
		return (1);
	if (direction == 4 && vars->map.map[i_col][i_row + 1] == '1')
		return (1);
	return (0);
}

void	move_up(t_vars *vars)
{
	if (vars->player.y - 64 >= 0
		&& !check_collision(vars, 1) && !check_black_hole(vars, 1))
	{
		if (check_stand_exit(vars))
			vars->map.map[vars->player.y / 64][vars->player.x / 64] = 'E';
		else
			vars->map.map[vars->player.y / 64][vars->player.x / 64] = '0';
		check_exit(vars, 1);
		vars->player.y -= 64;
		vars->player.nb++;
		check_collectible(vars);
		vars->player.nb1 *= -1;
	}
}

void	move_down(t_vars *vars)
{
	if (vars->player.y + 64 <= vars->screen.height - vars->player.height
		&& !check_collision(vars, 2) && !check_black_hole(vars, 2))
	{
		if (check_stand_exit(vars))
			vars->map.map[vars->player.y / 64][vars->player.x / 64] = 'E';
		else
			vars->map.map[vars->player.y / 64][vars->player.x / 64] = '0';
		check_exit(vars, 2);
		vars->player.y += 64;
		vars->player.nb++;
		check_collectible(vars);
		vars->player.nb1 *= -1;
	}
}

void	move_right(t_vars *vars)
{
	if (vars->player.x + 64 <= vars->screen.width - vars->player.width
		&& !check_collision(vars, 4) && !check_black_hole(vars, 4))
	{
		if (check_stand_exit(vars))
			vars->map.map[vars->player.y / 64][vars->player.x / 64] = 'E';
		else
			vars->map.map[vars->player.y / 64][vars->player.x / 64] = '0';
		check_exit(vars, 4);
		vars->player.x += 64;
		vars->player.nb++;
		check_collectible(vars);
		vars->player.nb1 *= -1;
	}
}

void	move_left(t_vars *vars)
{
	if (vars->player.x - 64 >= 0
		&& !check_collision(vars, 3) && !check_black_hole(vars, 3))
	{
		if (check_stand_exit(vars))
			vars->map.map[vars->player.y / 64][vars->player.x / 64] = 'E';
		else
			vars->map.map[vars->player.y / 64][vars->player.x / 64] = '0';
		check_exit(vars, 3);
		vars->player.x -= 64;
		vars->player.nb++;
		check_collectible(vars);
		vars->player.nb1 *= -1;
	}
}

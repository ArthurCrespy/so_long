/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:55:34 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/22 21:15:26 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_stand_exit(t_vars *vars)
{
	int	i_col;
	int	i_row;

	i_col = vars->player.y / 64;
	i_row = vars->player.x / 64;
	if (vars->map.map[i_col][i_row] == 'E')
		return (1);
	return (0);
}

void	check_exit(t_vars *vars, int direction)
{
	int	i_col;
	int	i_row;

	i_col = vars->player.y / 64;
	i_row = vars->player.x / 64;
	if (vars->coin.nb == 0)
	{
		if (direction == 1 && vars->map.map[i_col - 1][i_row] == 'E')
			mlx_exit(vars, "You win!\n", 0);
		if (direction == 2 && vars->map.map[i_col + 1][i_row] == 'E')
			mlx_exit(vars, "You win!\n", 0);
		if (direction == 3 && vars->map.map[i_col][i_row - 1] == 'E')
			mlx_exit(vars, "You win!\n", 0);
		if (direction == 4 && vars->map.map[i_col][i_row + 1] == 'E')
			mlx_exit(vars, "You win!\n", 0);
	}
	else
	{
		if (direction == 1 && vars->map.map[i_col - 1][i_row] == 'E')
			ft_putstr("You must collect all the coins!\n");
		if (direction == 2 && vars->map.map[i_col + 1][i_row] == 'E')
			ft_putstr("You must collect all the coins!\n");
		if (direction == 3 && vars->map.map[i_col][i_row - 1] == 'E')
			ft_putstr("You must collect all the coins!\n");
		if (direction == 4 && vars->map.map[i_col][i_row + 1] == 'E')
			ft_putstr("You must collect all the coins!\n");
	}
}

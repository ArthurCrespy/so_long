/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:14:39 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/23 00:17:06 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_position_x(t_vars *vars, char c)
{
	int	i_col;
	int	i_row;

	i_col = 0;
	while (vars->map.map[i_col])
	{
		i_row = 0;
		while (vars->map.map[i_col][i_row])
		{
			if (vars->map.map[i_col][i_row] == c)
				return (i_row);
			i_row++;
		}
		i_col++;
	}
	return (0);
}

int	get_position_y(t_vars *vars, char c)
{
	int	i_col;
	int	i_row;

	i_col = 0;
	while (vars->map.map[i_col])
	{
		i_row = 0;
		while (vars->map.map[i_col][i_row])
		{
			if (vars->map.map[i_col][i_row] == c)
				return (i_col);
			i_row++;
		}
		i_col++;
	}
	return (0);
}

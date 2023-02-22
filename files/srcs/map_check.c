/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:20:35 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/22 15:55:49 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_shape(t_vars *vars)
{
	int	i_col;
	int	i_row;

	i_col = 0;
	while (vars->map.map[i_col])
	{
		i_row = 0;
		while (vars->map.map[i_col][i_row])
			i_row++;
		if (i_row != ft_strlen(vars->map.map[0]))
			ft_exit("Error: Map is not rectangular/square\n", 1);
		i_col++;
	}
}

void	check_map_content(t_vars *vars)
{
	int	i_col;
	int	i_row;

	i_col = 0;
	while (vars->map.map[i_col])
	{
		i_row = 0;
		while (vars->map.map[i_col][i_row])
		{
			if (vars->map.map[i_col][i_row] != '1'
				&& vars->map.map[i_col][i_row] != '0'
				&& vars->map.map[i_col][i_row] != 'P'
				&& vars->map.map[i_col][i_row] != 'C'
				&& vars->map.map[i_col][i_row] != 'E')
				ft_exit("Error: Invalid character in map\n", 1);
			i_row++;
		}
		i_col++;
	}
}

void	check_map_objects(t_vars *vars)
{
	int	i_col;
	int	i_row;
	int	p_count;
	int	e_count;

	i_col = 0;
	p_count = 0;
	e_count = 0;
	while (vars->map.map[i_col])
	{
		i_row = 0;
		while (vars->map.map[i_col][i_row])
		{
			if (vars->map.map[i_col][i_row] == 'P')
				p_count++;
			if (vars->map.map[i_col][i_row] == 'E')
				e_count++;
			i_row++;
		}
		i_col++;
	}
	if (p_count != 1)
		ft_exit("Error: Map must have one player\n", 1);
	if (e_count != 1)
		ft_exit("Error: Map must have one player\n", 1);
}

void	check_map(t_vars *vars)
{
	check_map_shape(vars);
	check_map_content(vars);
	check_map_objects(vars);
}

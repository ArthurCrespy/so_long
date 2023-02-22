/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:15:41 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/22 21:15:42 by acrespy          ###   ########.fr       */
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
		{
			ft_free_map(vars);
			ft_exit("Error: Map must be rectangular or square\n", 1);
		}
		i_col++;
	}
}

void	check_map_letters(t_vars *vars)
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
			{
				ft_free_map(vars);
				ft_exit("Error: Invalid character in map\n", 1);
			}
			i_row++;
		}
		i_col++;
	}
}

void	check_map_player(t_vars *vars)
{
	int	i_col;
	int	i_row;
	int	p_count;

	i_col = 0;
	p_count = 0;
	while (vars->map.map[i_col])
	{
		i_row = 0;
		while (vars->map.map[i_col][i_row])
		{
			if (vars->map.map[i_col][i_row] == 'P')
				p_count++;
			i_row++;
		}
		i_col++;
	}
	if (p_count != 1)
	{
		ft_free_map(vars);
		ft_exit("Error: Map must have one player\n", 1);
	}
}

void	check_map_exit(t_vars *vars)
{
	int	i_col;
	int	i_row;
	int	e_count;

	i_col = 0;
	e_count = 0;
	while (vars->map.map[i_col])
	{
		i_row = 0;
		while (vars->map.map[i_col][i_row])
		{
			if (vars->map.map[i_col][i_row] == 'E')
				e_count++;
			i_row++;
		}
		i_col++;
	}
	if (e_count != 1)
	{
		ft_free_map(vars);
		ft_exit("Error: Map must have one exit\n", 1);
	}
}

void	check_map(t_vars *vars)
{
	check_map_shape(vars);
	check_map_letters(vars);
	check_map_player(vars);
	check_map_exit(vars);
}

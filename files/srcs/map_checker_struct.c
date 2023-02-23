/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:20:35 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/23 12:58:54 by acrespy          ###   ########.fr       */
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

void	check_map_walls(t_vars *vars)
{
	int	i_col;
	int	i_row;

	i_col = 0;
	while (vars->map.map[i_col])
	{
		i_row = 0;
		while (vars->map.map[i_col][i_row])
		{
			if (i_col == 0 || i_col == vars->map.height / 64 - 1
				|| i_row == 0 || i_row == vars->map.width / 64 - 1)
			{
				if (vars->map.map[i_col][i_row] != '1')
				{
					ft_free_map(vars);
					ft_exit("Error: Map must be surrounded by walls\n", 1);
				}
			}
			i_row++;
		}
		i_col++;
	}
}

void	check_map_path_coin(t_vars *vars)
{
	int	player_x;
	int	player_y;
	int	coins;

	player_x = get_position_x(vars, 'P');
	player_y = get_position_y(vars, 'P');
	coins = ft_flood_fill_coin(vars, vars->map.coin_map, player_x, player_y);
	if (coins != vars->coin.nb)
	{
		ft_free_map(vars);
		ft_exit("Error: Map must have a path to all the coins\n", 1);
	}
}

void	check_map_path_exit(t_vars *vars)
{
	int	player_x;
	int	player_y;
	int	exit;

	player_x = get_position_x(vars, 'P');
	player_y = get_position_y(vars, 'P');
	exit = ft_flood_fill_exit(vars, vars->map.exit_map, player_x, player_y);
	if (exit != 1)
	{
		ft_free_map(vars);
		ft_exit("Error: Map must have a path to the exit\n", 1);
	}
}

void	check_map_path(t_vars *vars)
{
	check_map_path_coin(vars);
	check_map_path_exit(vars);
}

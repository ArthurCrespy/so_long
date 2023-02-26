/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:16:08 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/22 21:16:15 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_objects(t_vars *vars)
{
	int	i_col;
	int	i_row;

	i_col = 0;
	vars->coin.nb = 0;
	while (vars->map.map[i_col])
	{
		i_row = 0;
		while (vars->map.map[i_col][i_row])
		{
			if (vars->map.map[i_col][i_row] == 'C')
				vars->coin.nb++;
			i_row++;
		}
		i_col++;
	}
	if (vars->coin.nb == 0)
	{
		ft_free_map(vars);
		ft_exit("Error: Map must have one collectible\n", 1);
	}
}

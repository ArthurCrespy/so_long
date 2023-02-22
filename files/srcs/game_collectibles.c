/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:55:28 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/22 18:48:20 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_collectible(t_vars *vars)
{
	int	i_col;
	int	i_row;

	i_col = vars->player.y / 64;
	i_row = vars->player.x / 64;
	if (vars->map.map[i_col][i_row] == 'C')
		vars->coin.nb--;
}

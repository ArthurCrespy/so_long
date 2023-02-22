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

void	check_map(t_vars *vars)
{
	check_map_shape(vars);
	check_map_walls(vars);
	check_map_path(vars);
	check_map_letters(vars);
	check_map_player(vars);
	check_map_exit(vars);
}

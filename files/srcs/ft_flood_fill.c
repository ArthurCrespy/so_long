/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:13:38 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/23 00:14:26 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_flood_fill_coin(t_vars *vars, char **map, int x, int y)
{
	int	nb;

	nb = 0;
	if (x < 0 || x >= vars->map.width
		|| y < 0 || y >= vars->map.height)
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'C')
		nb++;
	map[y][x] = '1';
	nb += ft_flood_fill_coin(vars, map, x + 1, y);
	nb += ft_flood_fill_coin(vars, map, x - 1, y);
	nb += ft_flood_fill_coin(vars, map, x, y + 1);
	nb += ft_flood_fill_coin(vars, map, x, y - 1);
	return (nb);
}

int	ft_flood_fill_exit(t_vars *vars, char **map, int x, int y)
{
	int	nb;

	nb = 0;
	if (x < 0 || x >= vars->map.width
		|| y < 0 || y >= vars->map.height)
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'E')
		nb++;
	map[y][x] = '1';
	nb += ft_flood_fill_exit(vars, map, x + 1, y);
	nb += ft_flood_fill_exit(vars, map, x - 1, y);
	nb += ft_flood_fill_exit(vars, map, x, y + 1);
	nb += ft_flood_fill_exit(vars, map, x, y - 1);
	return (nb);
}

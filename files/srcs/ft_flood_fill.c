/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:13:38 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/22 21:13:39 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by acrespy on 2/22/23.
//

int ft_flood_fill(char **map, char c, int x, int y, int width, int height)
{
	int nb;

	nb = 0;
	if (x < 0 || x >= width || y < 0 || y >= height)
		return (0);
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == c)
		nb++;
	map[y][x] = '1';
	nb += ft_flood_fill(map, c, x + 1, y, width, height);
	nb += ft_flood_fill(map, c, x - 1, y, width, height);
	nb += ft_flood_fill(map, c, x, y + 1, width, height);
	nb += ft_flood_fill(map, c, x, y - 1, width, height);
	return (nb);
}
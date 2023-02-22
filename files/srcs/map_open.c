/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:18:49 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/22 21:16:19 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_map(t_vars *vars, char *path)
{
	check_path(path);
	check_ext(path);
	read_map(vars, path);
	count_objects(vars);
	check_map(vars);
}

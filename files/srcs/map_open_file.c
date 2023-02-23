/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:16:03 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/22 21:16:06 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	save_map(t_vars *vars, char *map)
{
	vars->map.map = ft_split(map, '\n');
	vars->map.coin_map = ft_split(map, '\n');
	vars->map.exit_map = ft_split(map, '\n');
	vars->map.height = ft_strlen(map) / ft_strlen(vars->map.map[0]) * 64;
	vars->map.width = ft_strlen(vars->map.map[0]) * 64;
}

void	read_map(t_vars *vars, char *path)
{
	int		fd;
	char	*tmp;
	char	*gnl;
	char	*join;

	join = ft_calloc(sizeof (char), 1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(join);
		ft_exit("Error: Open failed\n", 1);
	}
	while (1)
	{
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
		tmp = join;
		join = ft_strjoin(tmp, gnl);
		free(tmp);
		free(gnl);
	}
	save_map(vars, join);
	free(join);
	close(fd);
}

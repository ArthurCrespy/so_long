/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:16:03 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/27 15:01:17 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit_map(char *gnl, char *join)
{
	free(gnl);
	free(join);
	ft_exit("Error: Map must not have void lines\n", 1);
}

void	save_map(t_vars *vars, char *map)
{
	vars->map.map = ft_split(map, '\n');
	vars->map.coin_map = ft_split(map, '\n');
	vars->map.exit_map = ft_split(map, '\n');
	vars->map.height = ft_strlen(map) / ft_strlen(vars->map.map[0]) * 64;
	vars->map.width = ft_strlen(vars->map.map[0]) * 64;
	free(map);
}

void	read_map(t_vars *vars, char *path)
{
	int		fd;
	char	*tmp;
	char	*gnl;
	char	*join;

	join = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_exit("Error: Open failed\n", 1);
	while (1)
	{
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
		if (ft_strlen(gnl) == 1)
			ft_exit_map(gnl, join);
		tmp = join;
		join = ft_strjoin(tmp, gnl);
		free(tmp);
		free(gnl);
	}
	if (ft_strlen(join) == 0)
		ft_exit("Error: Map must not be empty\n", 1);
	save_map(vars, join);
	close(fd);
}

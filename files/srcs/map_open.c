/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:18:49 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/22 18:48:47 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	save_map(t_vars *vars, char *map)
{
	vars->map.map = ft_split(map, '\n');
	vars->map.height = ft_strlen(map) / ft_strlen(vars->map.map[0]) * 64;
	vars->map.width = ft_strlen(vars->map.map[0]) * 64;
}

void	check_path(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
		ft_exit("Error: Path is a directory\n", 1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_exit("Error: File does not exist\n", 1);
	close(fd);
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
}

void	open_map(t_vars *vars, char *path)
{
	check_path(path);
	read_map(vars, path);
	check_map(vars);
	count_objects(vars);
}

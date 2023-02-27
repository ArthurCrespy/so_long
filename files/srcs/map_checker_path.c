/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:15:51 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/23 00:16:23 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_path(char *path)
{
	int		fd;

	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
		ft_exit("Error: Path is a directory\n", 1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_exit("Error: File does not exist\n", 1);
	close(fd);
}

void	check_ext(char *path)
{
	int		i_ext;
	int		i_path;
	char	*ext;

	i_ext = 0;
	i_path = ft_strlen(path) - 4;
	ext = ".ber";
	if (ft_strlen(path) <= 4 || path[i_path - 1] == '/')
		ft_exit("Error: File must be a .ber\n", 1);
	while (i_path != ft_strlen(path))
	{
		if (ft_compare(path[i_path], ext[i_ext]) == 0)
			ft_exit("Error: File must be a .ber\n", 1);
		i_path++;
		i_ext++;
	}
}

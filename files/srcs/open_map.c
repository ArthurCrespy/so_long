#include "../includes/so_long.h"

void	check_path(char *path)
{
	int fd;

	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
	{
		ft_exit("Error: Path is a directory\n", 1);
		exit(1);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_exit("Error: File does not exist\n", 1);
		exit(1);
	}
	close(fd);
}

void    save_map(t_vars *vars, char *map)
{
	vars->map.map = ft_split(map, '\n');
	vars->map.height = ft_strlen(map) / ft_strlen(vars->map.map[0]) * 64;
	vars->map.width = ft_strlen(vars->map.map[0]) * 64;
}


void read_map(t_vars *vars, char *path)
{
	int fd;
	char *tmp;
	char *gnl;
	char *join;

	join = calloc(sizeof (char), 1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_exit("Error: Open failed\n", 1);
		free(join);
		exit(1);
	}
	while (1)
	{
		gnl = get_next_line(fd);
		if (!gnl)
			break;
		tmp = join;
		join = ft_strjoin(tmp, gnl);
		free(tmp);
		free(gnl);
	}
	save_map(vars, join);
	free(join);
	close(fd);
}

void    open_map(t_vars *vars, char *path)
{
	check_path(path);
	read_map(vars, path);
	check_map(vars);
}
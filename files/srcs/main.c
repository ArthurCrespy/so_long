/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:30:49 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/08 17:29:50 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

void	mlx_free(t_vars *vars)
{
	int i;

	i = 0;
	while (vars->map[i])
	{
		printf("%s\n", vars->map[i]);
		free(vars->map[i]);
		i++;
	}
	if (vars->background.img)
		mlx_destroy_image(vars->mlx, vars->background.img);
	if (vars->player.img)
		mlx_destroy_image(vars->mlx, vars->player.img);
	if (vars->coin.img)
		mlx_destroy_image(vars->mlx, vars->coin.img);
	if (vars->wall.img)
		mlx_destroy_image(vars->mlx, vars->wall.img);
	if (vars->exit.img)
		mlx_destroy_image(vars->mlx, vars->exit.img);
	if (vars->mlx_win)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	if (vars->mlx_win)
		mlx_destroy_display(vars->mlx);
	if (vars->mlx)
		free(vars->mlx);
	if (vars->map)
		free(vars->map);
	exit(0);
}

int	check_collision(t_vars *vars, int direction)
{
	(void)direction;
	(void)vars;
/*	while (vars->wall->next != NULL)
	{
		if (direction == 1
		    && vars->player.y == vars->wall->y + vars->wall->height)
			return (1);
		if (direction == 2 && vars->player.y + vars->player.height == vars->wall->y)
			return (1);
		if (direction == 3 && vars->player.x == vars->wall->x + vars->wall->width)
			return (1);
		if (direction == 4 && vars->player.x + vars->player.width == vars->wall->x)
			return (1);
		else
			vars->wall = vars->wall->next;
	}*/
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	printf("key pressed %d\n", keycode);
	if (keycode == 65307)
		mlx_free(vars);
	if (keycode == 65361 && vars->player.x - 64 >= 0
		&& !check_collision(vars, 3))
			vars->player.x -= 64;
	if (keycode == 65362 && vars->player.y - 64 >= 0
		&& !check_collision(vars, 1))
			vars->player.y -= 64;
	if (keycode == 65363
		&& vars->player.x + 64 <= vars->background.width - vars->player.width
		&& !check_collision(vars, 4))
			vars->player.x += 64;
	if (keycode == 65364
		&& vars->player.y + 64 <= vars->background.height - vars->player.height
		&& !check_collision(vars, 2))
			vars->player.y += 64;
	return (0);
}

int	render_frame(t_vars *vars)
{
	int i_col;
	int i_row;

	i_col = 0;
	i_row = 0;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->background.img, 0, 0);
	while (vars->map[i_col])
	{
		while (vars->map[i_col][i_row])
		{
			if (vars->map[i_col][i_row] == '1')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->wall.img, i_row * 64, i_col * 64);
			if (vars->map[i_col][i_row] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player.img, i_row * 64, i_col * 64);
			if (vars->map[i_col][i_row] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->coin.img, i_row * 64, i_col * 64);
			if (vars->map[i_col][i_row] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->exit.img, i_row * 64, i_col * 64);
			i_row++;
		}
		i_col++;
	}
	usleep(100000 / 120);
	return (0);
}

void	mlx_initialize(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		mlx_free(vars);
	vars->mlx_win = mlx_new_window(vars->mlx, 800, 600, "So Long!");
	if (!vars->mlx_win)
		mlx_free(vars);
}

void	mlx_initialize_img(t_vars *vars)
{
	vars->background.path = "./../assets/background.xpm";
	vars->background.img = mlx_xpm_file_to_image(vars->mlx, vars->background.path, &vars->background.width, &vars->background.height);
	if (!vars->background.img)
		mlx_free(vars);
	vars->wall.x = 64;
	vars->wall.y = 64;
	vars->wall.path = "./../assets/wall.xpm";
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, vars->wall.path, &vars->wall.width, &vars->wall.height);
	if (!vars->wall.img)
		mlx_free(vars);
	vars->player.x = 64;
	vars->player.y = 64;
	vars->player.path = "./../assets/sly_cooper.xpm";
	vars->player.img = mlx_xpm_file_to_image(vars->mlx, vars->player.path, &vars->player.width, &vars->player.height);
	if (!vars->player.img)
		mlx_free(vars);
	vars->coin.x = 64;
	vars->coin.y = 64;
	vars->coin.path = "./../assets/coin.xpm";
	vars->coin.img = mlx_xpm_file_to_image(vars->mlx, vars->coin.path, &vars->coin.width, &vars->coin.height);
	if (!vars->coin.img)
		mlx_free(vars);
	vars->exit.x = 64;
	vars->exit.y = 64;
	vars->exit.path = "./../assets/sly_cooper.xpm";
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, vars->exit.path, &vars->exit.width, &vars->exit.height);
	if (!vars->exit.img)
		mlx_free(vars);
}

void open_map(t_vars *vars, char *path)
{
	int fd;
	char *gnl;
	char *join;
	char *tmp;

	gnl = "";
	tmp = "";
	join = calloc(sizeof (char), 1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
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
	vars->map = ft_split(join, '\n');
	free(join);
	close(fd);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void)argc;
	mlx_initialize(&vars);
	mlx_initialize_img(&vars);
	open_map(&vars, argv[1]);
	mlx_hook(vars.mlx_win, 2, 1L << 0, (int (*)(void)) key_press, &vars);
	mlx_hook(vars.mlx_win, 17, 1L << 17, (int (*)(void)) mlx_free, &vars);
	mlx_loop_hook(vars.mlx, (int (*)(void)) render_frame, &vars);
	mlx_loop(vars.mlx);
	mlx_free(&vars);
	return (0);
}

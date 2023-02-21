#include "../includes/so_long.h"

int	key_press(int keycode, t_vars *vars)
{
	printf("key pressed %d\n", keycode);
	if (keycode == 65307)
		mlx_free(vars);
	if (keycode == 65361)
		move_left(vars);
	if (keycode == 65362)
		move_up(vars);
	if (keycode == 65363)
		move_right(vars);
	if (keycode == 65364)
		move_down(vars);

	int i = 0;
	while (vars->map.map[i])
	{
		printf("map: %s\n", vars->map.map[i]);
		i++;
	}
	return (0);
}

int	render_frame(t_vars *vars)
{
	int i_col;
	int i_row;

	i_col = 0;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->background.img, 0, 0);
	while (vars->map.map[i_col])
	{
		i_row = 0;
		while (vars->map.map[i_col][i_row])
		{
			if (vars->map.map[i_col][i_row] == '1')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->wall.img, i_row * 64, i_col * 64);
			else if (vars->map.map[i_col][i_row] == 'P')
			{
				vars->player.x = i_row * 64;
				vars->player.y = i_col * 64;
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player.img, i_row * 64, i_col * 64);
			}
			else if (vars->map.map[i_col][i_row] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->coin.img, i_row * 64, i_col * 64);
			else if (vars->map.map[i_col][i_row] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->exit.img, i_row * 64, i_col * 64);
			i_row++;
		}
		i_col++;
	}
	usleep(100000 / 120);
	return (0);
}

void    mlx_run(t_vars *vars)
{
	mlx_hook(vars->mlx_win, 2, 1L << 0, (int (*)(void)) key_press, &vars);
	mlx_hook(vars->mlx_win, 17, 1L << 17, (int (*)(void)) mlx_free, &vars);
	mlx_loop_hook(vars->mlx, (int (*)(void)) render_frame, &vars);
	mlx_loop(vars->mlx);
}
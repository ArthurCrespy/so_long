#include "./../mlx_linux/mlx.h"
#include "./../mlx_linux/mlx_int.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	mlx_free(t_vars *vars)
{
	if (vars->background.img)
		mlx_destroy_image(vars->mlx, vars->background.img);
	if (vars->player.img)
		mlx_destroy_image(vars->mlx, vars->player.img);
	if (vars->mlx_win)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	if (vars->mlx_win)
		mlx_destroy_display(vars->mlx);
	if (vars->mlx)
		free(vars->mlx);
	exit(0);
}

int	check_collision(t_vars *vars, int direction)
{
	if (direction == 1
		&& vars->player.y == vars->wall.y + vars->wall.height)
		return (1);
	if (direction == 2 && vars->player.y + vars->player.height == vars->wall.y)
		return (1);
	if (direction == 3 && vars->player.x == vars->wall.x + vars->wall.width)
		return (1);
	if (direction == 4 && vars->player.x + vars->player.width == vars->wall.x)
		return (1);
	else
		return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	printf("key pressed %d\n", keycode);
	if (keycode == 65307)
		mlx_free(vars);
	if (keycode == 65361 && vars->player.x - 64 >= 0)
		vars->player.x -= 64;
	if (keycode == 65362 && vars->player.y - 64 >= 0)
		vars->player.y -= 64;
	if (keycode == 65363 && vars->player.x + 64 <= vars->background.width - vars->player.width)
		vars->player.x += 64;
	if (keycode == 65364&& vars->player.y + 64 <= vars->background.height - vars->player.height)
		vars->player.y += 64;
	return (0);
}

int	render_frame(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->background.img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player.img, vars->player.x, vars->player.y);
	usleep(100000/120);
	return (0);
}

void mlx_initialize(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		mlx_free(vars);

	vars->mlx_win = mlx_new_window(vars->mlx, 800, 600, "So Long!");
	if (!vars->mlx_win)
		mlx_free(vars);
}

void mlx_initialize_img(t_vars *vars)
{
	vars->background.path = "./../assets/background.xpm";
	vars->background.img = mlx_xpm_file_to_image(vars->mlx, vars->background.path, &vars->background.width, &vars->background.height);
	if (!vars->background.img)
		mlx_free(vars);

	vars->player.x = 0;
	vars->player.y = 0;
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
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);

	mlx_hook(vars.mlx_win, 2, 1L<<0, (int (*)(void)) key_press, &vars);
	mlx_loop_hook(vars.mlx, (int (*)(void)) render_frame, &vars);
	mlx_loop(vars.mlx);


	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img.img, 0, 0);

	//mlx_loop(vars.mlx);

	//sleep(3);

	mlx_free(vars);

	return (0);
}
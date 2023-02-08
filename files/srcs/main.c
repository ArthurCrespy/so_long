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

int render_frame(t_vars vars)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img.img, 0, 0);
	return (0);
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
#include "../includes/so_long.h"

int	check_collision(t_vars *vars, int direction)
{
	int i_col;
	int i_row;

	i_col = vars->player.y / 64;
	i_row = vars->player.x / 64;

	int i = 0;
	while (vars->map.map[i])
	{
		printf("map: %s\n", vars->map.map[i]);
		i++;
	}

	if (direction == 1 && vars->map.map[i_col - 1][i_row] == '1')
		return (1);
	if (direction == 2 && vars->map.map[i_col + 1][i_row] == '1')
		return (1);
	if (direction == 3 && vars->map.map[i_col][i_row - 1] == '1')
		return (1);
	if (direction == 4 && vars->map.map[i_col][i_row + 1] == '1')
		return (1);
	return (0);
}

void    move_right(t_vars *vars)
{
	if (vars->player.x + 64 <= vars->screen.width - vars->player.width
	    && !check_collision(vars, 4))
	{
		vars->map.map[vars->player.y / 64][vars->player.x / 64] = '0';
		vars->player.x += 64; // direction 4 = right
		vars->map.map[vars->player.y / 64][vars->player.x / 64] = 'P';
	}
}

void    move_left(t_vars *vars)
{
	if (vars->player.x - 64 >= 0
	    && !check_collision(vars, 3))
	{
		vars->map.map[vars->player.y / 64][vars->player.x / 64] = '0';
		vars->player.x -= 64; // direction 3 = left
		vars->map.map[vars->player.y / 64][vars->player.x / 64] = 'P';
	}
}

void    move_up(t_vars *vars)
{
	if (vars->player.y - 64 >= 0
	    && !check_collision(vars, 1))
	{
		vars->map.map[vars->player.y / 64][vars->player.x / 64] = '0';
		vars->player.y -= 64; // direction 1 = up
		vars->map.map[vars->player.y / 64][vars->player.x / 64] = 'P';
	}
}

void    move_down(t_vars *vars)
{
	if (vars->player.y + 64 <= vars->screen.height - vars->player.height
	    && !check_collision(vars, 2))
	{
		vars->map.map[vars->player.y / 64][vars->player.x / 64] = '0';
		vars->player.y += 64; // direction 2 = down
		vars->map.map[vars->player.y / 64][vars->player.x / 64] = 'P';
	}
}
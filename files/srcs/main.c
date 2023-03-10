/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:30:49 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/22 21:15:37 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	check_args(argc, argv);
	open_map(&vars, argv[1]);
	mlx_initialize_win(&vars);
	mlx_initialize_img(&vars);
	mlx_loop_hook(vars.mlx, (int (*)(void)) render_frame, &vars);
	mlx_hook(vars.mlx_win, 2, 1L << 0, (int (*)(void)) key_press, &vars);
	mlx_hook(vars.mlx_win, 17, 1L << 17, (int (*)(void)) mlx_hook_exit, &vars);
	mlx_loop(vars.mlx);
	mlx_free(&vars);
	return (0);
}

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

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void)argc;
	open_map(&vars, argv[1]);
	mlx_initialize(&vars);
	mlx_run(&vars);
	mlx_free(&vars);
	return (0);
}

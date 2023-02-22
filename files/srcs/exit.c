/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:16:08 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/22 15:55:58 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit(char *msg, int status)
{
	ft_putstr(msg);
	exit(status);
}

void	mlx_exit(t_vars *vars, char *msg, int status)
{
	mlx_free(vars);
	ft_exit(msg, status);
}

void	mlx_hook_exit(t_vars *vars)
{
	mlx_free(vars);
	exit(0);
}

void	mlx_error(t_vars *vars)
{
	mlx_free(vars);
	ft_exit("Error: Something went wrong with MiniLibX\n", 1);
}

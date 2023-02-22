/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:49:16 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/22 18:50:52 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_args(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		ft_exit("Error: Wrong number of arguments\n", 2);
}

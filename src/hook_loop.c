/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:38:10 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/02 10:41:40 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	all_hooks(t_map *map)
{
	mlx_loop_hook(map->mlx, close_esc, map);
	mlx_loop_hook(map->mlx, move, map);
	mlx_loop_hook(map->mlx, zoom, map);
	mlx_loop_hook(map->mlx, change_z, map);
	mlx_loop_hook(map->mlx, recenter, map);
}

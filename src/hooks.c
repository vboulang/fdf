/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:33:44 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/25 14:07:32 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	close_esc(void *param)
{
	t_map	*map;
	
	map = (t_map *)param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
	{
		//FREE struct
		mlx_close_window(map->mlx);
	}
}

void	all_hooks(t_map *map)
{

	mlx_loop_hook(map->mlx, close_esc, map);
}

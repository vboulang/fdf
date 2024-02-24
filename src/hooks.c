/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:33:44 by vboulang          #+#    #+#             */
/*   Updated: 2024/02/23 20:23:40 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

//Make a func to free struct
void	close_esc(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
}

void	move(void *param)
{
	t_map		*map;

	map = (t_map *)param;
	if(mlx_is_key_down(map->mlx, MLX_KEY_A)
		|| mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		map->h_dis -= 5;
	else if(mlx_is_key_down(map->mlx, MLX_KEY_W)
		|| mlx_is_key_down(map->mlx, MLX_KEY_UP))
		map->v_dis -= 5;
	else if(mlx_is_key_down(map->mlx, MLX_KEY_S)
		|| mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		map->v_dis += 5;
	else if(mlx_is_key_down(map->mlx, MLX_KEY_D)
		|| mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->h_dis += 5;
	update_point(map);
	fill_background(map->img);
	draw(map);
}

void	zoom(void *param)
{
	t_map		*map;

	map = (t_map *)param;
	if(mlx_is_key_down(map->mlx, MLX_KEY_Q) && map->zoomf <= 20)
		map->zoomf += 0.05;
	else if(mlx_is_key_down(map->mlx, MLX_KEY_E) && map->zoomf >= 0.1)
		map->zoomf -= 0.05;
	update_point(map);
	fill_background(map->img);
	draw(map);
}

void	change_z(void *param)
{
	t_map		*map;

	map = (t_map *)param;
	if(mlx_is_key_down(map->mlx, MLX_KEY_X))
		map->scalez += 0.05;
	else if(mlx_is_key_down(map->mlx, MLX_KEY_Z))
		map->scalez -= 0.05;
	update_point(map);
	fill_background(map->img);
	draw(map);
}

void	recenter(void *param)
{
	t_map		*map;

	map = (t_map *)param;
	if(mlx_is_key_down(map->mlx, MLX_KEY_P))
	{
		map->h_dis = 0;
		map->v_dis = 0;
		map->zoomf = 1.5;
		map->scalez = 1;
	}
	update_point(map);
	fill_background(map->img);
	draw(map);
}

void	all_hooks(t_map *map)
{
	mlx_loop_hook(map->mlx, close_esc, map);
	mlx_loop_hook(map->mlx, move, map);
	mlx_loop_hook(map->mlx, zoom, map);
	mlx_loop_hook(map->mlx, change_z, map);
	mlx_loop_hook(map->mlx, recenter, map);
}

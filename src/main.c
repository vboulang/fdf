/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:38:05 by vboulang          #+#    #+#             */
/*   Updated: 2024/02/09 17:13:54 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://pikuma.com/blog/isometric-projection-in-games
#include "../inc/fdf.h"

void	initialize_map(t_map *map, char *str)
{
	map->height = 0;
	map->width = 0;
	map->point = NULL;
	map->filename = str;
	//IF ERROR
}

void	initialize_mlx_window(t_map *map)
{
	if (map->window_height > 1000)
		map->window_height = 1000;
	if (map->window_width > 1500)
		map->window_width = 1500;
	map->mlx = mlx_init(map->window_width, map->window_height, "Fdf", true);
}

void	fill_background(t_map *map, mlx_image_t *img)
{
	int i;
	int j;
	
	i = 0;
	while (i < map->window_height)
	{
		j = 0;
		while (j < map->window_width)
		{
			mlx_put_pixel(img, j, i, 0x000000FF);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map		map;
	mlx_image_t	*img;
	int x;
	int y;

	if (argc == 2)
	{
		initialize_map(&map, argv[1]);
		get_map_size(argv[1], &map);
		initialize_mlx_window(&map);
		img = mlx_new_image(map.mlx, map.window_width, map.window_height); //IF ERROR DO SOMETHING
		ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
		mlx_image_to_window(map.mlx, img, 0, 0);
		fill_background(&map, img);
		y = 0;
		//dprintf(2, "%d %d\n", map.width, map.height);
		while (y < map.height)
		{
			x = 0;
			while (x < map.width)
			{
				if(((map.point[y][x].isox) + map.window_width/2 < map.window_width) && (map.window_height/4 + (map.point[y][x].isoy) < map.window_height)
					&& ((map.point[y][x].isox) + map.window_width/2 > 0) && (map.window_height/4 + (map.point[y][x].isoy) > 0))
				mlx_put_pixel(img, (map.point[y][x].isox) + map.window_width/2, map.window_height/4 + (map.point[y][x].isoy), map.point[y][x].color);
				x++;
			}
			y++;
		}
		// pixel_map(&map);
		all_hooks(&map);
		mlx_loop(map.mlx);
		mlx_terminate(map.mlx);
	}
	else
	{
		if (argc > 2)
			printf("Too many arguments.\n");
		else
			printf("Please provide arguments.\n");
		return (1);
	}
	return (0);
}

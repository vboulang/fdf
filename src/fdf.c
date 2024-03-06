/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:38:05 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/06 15:06:25 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	fill_background(mlx_image_t *img)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			mlx_put_pixel(img, j, i, 0x000000FF);
			j++;
		}
		i++;
	}
}

void	draw_points(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->point[y][x].isox < map->img->width
				&& map->point[y][x].isoy < map->img->height
				&& map->point[y][x].isox > 0 && map->point[y][x].isoy > 0)
				mlx_put_pixel(map->img, map->point[y][x].isox,
					map->point[y][x].isoy, map->point[y][x].color);
			x++;
		}
		y++;
	}
}

void	draw(t_map *map)
{
	int	x;
	int	y;

	draw_points(map);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x + 1 < map->width)
				choose_case(map->img, &map->point[y][x], &map->point[y][x + 1]);
			if (y + 1 < map->height)
				choose_case(map->img, &map->point[y][x], &map->point[y + 1][x]);
			if (x - 1 >= 0)
				choose_case(map->img, &map->point[y][x], &map->point[y][x - 1]);
			if (y - 1 >= 0)
				choose_case(map->img, &map->point[y][x], &map->point[y - 1][x]);
			x++;
		}
		y++;
	}
}

void	mlx_func(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "Fdf", true);
	if (!map->mlx)
	{
		printf("Failed to initialize mlx.\n");
		free_map(map);
		exit(EXIT_FAILURE);
	}
	map->img = mlx_new_image(map->mlx, 3 * WIDTH, 3 * HEIGHT);
	if (!map->img)
	{
		printf("Problem creating the image.\n");
		free_map(map);
		exit(EXIT_FAILURE);
	}
	ft_memset(map->img->pixels, 0,
		map->img->width * map->img->height * sizeof(int32_t));
	fill_background(map->img);
	draw(map);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
	all_hooks(map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
}

int	main(int argc, char **argv)
{
	t_map		map;

	if (argc == 2)
	{
		initialize_map(&map, argv[1]);
		get_map_size(argv[1], &map);
		mlx_func(&map);
		free_map(&map);
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

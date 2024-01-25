/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:38:05 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/25 17:49:59 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	initialize_map(t_map *map, char *str)
{
	map->height = 0;
	map->wide = 0;
	map->point = NULL;
	map->filename = str;
	map->mlx = mlx_init(1000, 1000, "Fdf", true);
	//IF ERROR
}

int	main(int argc, char **argv)
{
	t_map		map;
	mlx_image_t	*img;
	
	if (argc == 2)
	{
		initialize_map(&map, argv[1]);
		get_map_size(argv[1], &map);
		img = mlx_new_image(map.mlx, 1000, 1000);
		//IF ERROR
		ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
   		mlx_image_to_window(map.mlx, img, 0, 0);
		// int i;
		// int j;
		// i = 250;
		// while(i < 750)
		// {
		// 	j = 250;
		// 	while(j < 750)
		// 	{
		// 		mlx_put_pixel(img, i, j, 0x000420FF);
		// 		j++;
		// 	}
		// 	i++;
		// }
		mlx_put_pixel(img, 250, 250, 0x000420FF);

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

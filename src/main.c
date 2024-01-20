/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:38:05 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/20 15:34:21 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	initialize_map(t_map *map, char *str)
{
	map->height = 0;
	map->wide = 0;
	map->point = NULL;
	map->filename = str;
}

int	main(int argc, char **argv)
{
	t_map map;
	
	if (argc == 2)
	{
		initialize_map(&map, argv[1]);
		get_map_size(argv[1], &map);

		//TODO execute some mlx magic
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

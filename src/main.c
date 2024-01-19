/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:38:05 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/19 18:19:00 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	initialize(t_map *map)
{
	map->height = 0;
	map->wide = 0;
	map->map = NULL;
}

int	main(int argc, char **argv)
{
	t_map map;
	
	if (argc == 2)
	{
		//initialize(&map);
		get_map_size(argv[1], &map);
		get_info(argv[1]);
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

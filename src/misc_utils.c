/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:40:49 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/02 12:48:20 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	check_map(t_map *map)
{
	char	*line;

	line = ft_strtrim(get_next_line(map->fd), "\n");
	while (line)
	{
		if (get_col_nb(line) != map->width)
		{
			free_and_null(line);
			return (-1);
		}
		free_and_null(line);
		line = ft_strtrim(get_next_line(map->fd), "\n");
	}
	free_and_null(line);
	return (0);
}

void	load_map_error(t_map *map, char **strs)
{
	free_all(strs);
	close(map->fd);
	exit(EXIT_FAILURE);
}

void	initialize_map(t_map *map, char *str)
{
	map->height = 0;
	map->width = 0;
	map->scale = 1;
	map->h_dis = 0;
	map->v_dis = 0;
	map->zoomf = 1.5;
	map->scalez = 1;
	map->point = NULL;
	map->filename = str;
}

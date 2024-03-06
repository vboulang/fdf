/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:40:49 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/06 15:24:59 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

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

void	string_mlx(t_map *map)
{
	mlx_put_string(map->mlx, "Move : A, W, S, D or LEFT, UP, DOWN, RIGHT",
		10, 10);
	mlx_put_string(map->mlx, "Zoom : Q, E", 10, 30);
	mlx_put_string(map->mlx, "Change height : Z, X", 10, 50);
	mlx_put_string(map->mlx, "Return settings to default : P", 10, 70);
	mlx_put_string(map->mlx, "Close window : ESC", 10, 90);
}

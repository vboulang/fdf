/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:45:46 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/02 11:28:27 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	create_point(t_map *map, int i, int j, char **splitted_line)
{
	char	**carac;
	t_point	pt;

	pt.x = i;
	pt.y = j;
	pt.map = map;
	if (ft_strchr(splitted_line[j], ','))
	{
		carac = ft_split(splitted_line[j], ',');
		if (!carac)
			load_map_error(map, splitted_line);
		pt.z = ft_atoi(carac[0]);
		pt.color = ft_atoi_base(carac[1], "0123456789ABCDEF");
		free_all(carac);
	}
	else
	{
		pt.z = ft_atoi(splitted_line[j]);
		pt.color = 0xFFFFFFFF;
	}
	isometric_conversion(&pt);
	return (pt);
}

void	filler(t_map *map)
{
	int		i;
	int		j;
	char	*line;
	char	**splitted_line;

	i = 0;
	while (i < map->height)
	{
		line = ft_strtrim(get_next_line(map->fd), "\n");
		splitted_line = ft_split(line, ' ');
		j = 0;
		while (j < map->width)
		{
			map->point[i][j] = create_point(map, i, j, splitted_line);
			j++;
		}
		if (splitted_line)
			free_all(splitted_line);
		if (line)
			free(line);
		i++;
	}
}

void	fill_map(t_map *map)
{
	map->fd = open(map->filename, O_RDONLY);
	if (map->fd == -1)
	{
		printf("File couldn't be opened.");
		free_map(map);
		exit(EXIT_FAILURE);
	}
	if (check_map(map) == -1)
	{
		printf("Invalid file. Please input valid map file.");
		free_map(map);
		close(map->fd);
		exit(EXIT_FAILURE);
	}
	close(map->fd);
	map->fd = open(map->filename, O_RDONLY);
	if (map->fd == -1)
	{
		printf("File couldn't be opened.");
		free_map(map);
		exit(EXIT_FAILURE);
	}
	filler(map);
	close(map->fd);
}

/*
	Need to add a free functon for points
*/
void	create_map(t_map *map, int line_count, int col_count)
{
	int		i;
	t_point	**point;

	i = 0;
	set_window_restriction(map, line_count, col_count);
	point = ft_calloc((line_count + 1), sizeof(t_point *));
	if (!point)
	{
		perror("Couldn't load map");
		exit(EXIT_FAILURE);
	}
	while (i < line_count)
	{
		point[i] = ft_calloc((col_count + 1), sizeof(t_point));
		if (!point)
		{
			perror("Couldn't load map point");
			free_all_map(point);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	map->point = point;
	fill_map(map);
}

void	get_map_size(char *file, t_map *map)
{
	char	*line;
	int		line_count;
	int		col_count;

	line_count = 0;
	map->fd = open(file, O_RDONLY);
	if (map->fd == -1)
	{
		perror("File couldn't be opened.");
		exit(EXIT_FAILURE);
	}
	line = ft_strtrim(get_next_line(map->fd), "\n");
	if (line)
		col_count = get_col_nb(line);
	while (line)
	{
		line_count++;
		free_and_null(line);
		line = get_next_line(map->fd);
	}
	free_and_null(line);
	close(map->fd);
	create_map(map, line_count, col_count);
}

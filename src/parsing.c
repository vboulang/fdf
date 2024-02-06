/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:45:46 by vboulang          #+#    #+#             */
/*   Updated: 2024/02/02 15:12:40 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

//DO NOT KEEP?
void	printf_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%d ", map->point[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n\n\n\n");
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("u: %0.3f v: %0.3f   ",
				map->point[i][j].isox, map->point[i][j].isoy);
			j++;
		}
		printf("\n");
		i++;
	}
}

t_point	create_point(int i, int j, char **splitted_line)
{
	char	**carac;
	t_point	pt;

	pt.x = i;
	pt.y = j;
	if (ft_strchr(splitted_line[j], ','))
	{
		carac = ft_split(splitted_line[j], ',');
		if (!carac)
			exit(EXIT_FAILURE); ///
		pt.z = ft_atoi(carac[0]);
		pt.color = carac[1]; //TO CHECK IF int IS THE RIGHT TYPE ft_atoi(carac[1])
	}
	else
	{
		pt.z = ft_atoi(splitted_line[j]);
		pt.color = ""; //DEFAULT COLOR??
	}
	isometric_conversion(&pt);
	return (pt);
}

void	fill_map(t_map *map)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**splitted_line;

	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
	{
		printf("File couldn't be opened.");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < map->height)
	{
		line = ft_strtrim(get_next_line(fd), "\n");
		splitted_line = ft_split(line, ' ');
		j = 0;
		while (j < map->width)
		{
			map->point[i][j] = create_point(i, j, splitted_line);
			j++;
		}
		i++;
	}
	if (line)
		free(line);
	if (splitted_line)
		free_all(splitted_line);
	close(fd);
}

void	create_map(t_map *map, int line_count, int col_count)
{
	int		i;
	t_point	**point;

	i = 0;
	map->height = line_count;
	map->width = col_count;
	map->window_height = map->height * 40;
	map->window_width = map->width * 50;
	point = ft_calloc((line_count + 1), sizeof(t_point *));
	if (!point)
	{
		printf("Couldn't load map");
		exit(EXIT_FAILURE);
	}
	while (i < line_count)
	{
		point[i] = ft_calloc((col_count + 1), sizeof(t_point));
		if (!point)
		{
			printf("Couldn't load map point");
			free_all_map(point);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	map->point = point;
	fill_map(map);
	//printf_map(map); ///////
	// FREE_MAP FUNCTION
}

void	free_and_null(char *str)
{
	free(str);
	str = NULL;
}

void	free_all_map(t_point **point)
{
	int	i;

	i = 0;
	while (point[i])
		i++;
	i--;
	while (i >= 0)
	{
		free(point[i]);
		point[i] = NULL;
		i--;
	}
	free(point);
	point = NULL;
}

void	free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	i--;
	while (i >= 0)
	{
		free_and_null(strs[i]);
		i--;
	}
	free(strs);
	strs = NULL;
}

int	get_col_nb(char *line)
{
	char	**splitted_line;
	int		i;

	splitted_line = ft_split(line, ' ');
	i = 0;
	while (splitted_line[i])
		i++;
	free_all(splitted_line);
	return (i);
}

void	get_map_size(char *file, t_map *map)
{
	char	*line;
	int		fd;
	int		line_count;
	int		col_count;

	line_count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("File couldn't be opened.");
		exit(EXIT_FAILURE);
	}
	line = ft_strtrim(get_next_line(fd), "\n");
	if (line)
		col_count = get_col_nb(line);
	while (line)
	{
		line_count++;
		free_and_null(line);
		line = get_next_line(fd);
	}
	close(fd);
	create_map(map, line_count, col_count);
	free_and_null(line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:45:46 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/22 16:30:36 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	load_map(t_map *map, int line_count, int col_count)
{
	int		i;
	int		j;
	int 	fd;
	char	*line;
	t_point	**point;
	t_point	pt;
	char	**splitted_line;
	char	**carac;
	
	i = 0;
	map->height = line_count;
	map->wide = col_count;
	point = ft_calloc((line_count + 1), sizeof(t_point *));
	if(!point)
	{
		printf("Couldn't load map");
		exit(EXIT_FAILURE);
	}
	while(i < line_count)
	{
		point[i] = ft_calloc(col_count, sizeof(t_point));
		if(!point)
		{
			printf("Couldn't load map point");
			free_all_map(point);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	map->point = point;
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
	{
		printf("File couldn't be opened.");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while(i < map->height)
	{
		line = get_next_line(fd);
		splitted_line = ft_split(line, ' ');
		j = 0;
		while(j < map->wide)
		{
			pt.x = i;
			pt.z = j;
			if (ft_strchr(splitted_line[j], ','))
			{
				carac = ft_split(splitted_line[j], ',');
				pt.y = ft_atoi(carac[0]);
				pt.color = ft_atoi(carac[1]); //TO CHECK IF int IS THE RIGHT TYPE
			}
			else
				pt.y = ft_atoi(splitted_line[j]); //DEFAULT COLOR??
			j++;
		}
		i++;
	} ////////WRITE A FUNCTION TO PRINT EVERY MAP POINT
	free(line);
	free_all(splitted_line);
	if(carac)
		free_all(carac);
	close(fd);
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
	while(point[i])
		i++;
	i--;
	while(i >= 0)
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
	while(strs[i])
		i++;
	i--;
	while(i >= 0)
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
	while(splitted_line[i])
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
	line = get_next_line(fd);
	if(line)
		col_count = get_col_nb(line);
	while (line)
	{
		line_count++;
		free_and_null(line);
		line = get_next_line(fd);
	}
	close(fd);
	load_map(map, line_count, col_count);
	free_and_null(line);
}

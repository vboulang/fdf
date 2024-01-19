/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:45:46 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/19 18:19:18 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	load_map(t_map *map, int line_count, int col_count)
{
	int array[line_count][col_count];
	int	i;
	int	j;

	i = 0;
	map->height = line_count;
	map->wide = col_count;
	while(i < line_count)
	{
		j = 0;
		while(j < col_count)
		{
			array[i][j] = 0;
			j++;
		}
		i++;
	}
	map->map = array;
}

void	free_and_null(char *str)
{
	free(str);
	str = NULL;
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
		line = get_next_line(fd);
	}
	close(fd);
	load_map(map, line_count, col_count);
	free_and_null(line);
}

void	get_info(char *file)
{
	char	**splitted_line;
	int		fd;
	char	*line;

	(void)splitted_line;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("File couldn't be opened.");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		//TODO how to stock each line? struct? int table? 
		//TODO extract color information if I want...
		line = get_next_line(fd); //free avant?
	}
	close(fd);
}

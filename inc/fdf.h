/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:52:05 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/19 18:21:17 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "../libft/inc/libft.h"

typedef struct s_map
{
	int	height;
	int	wide;
	int	*map;
	//int	**col_map;
}       t_map;

int		main(int argc, char **argv);
void	initialize(t_map *map);

void	get_info(char *file);
void	get_map_size(char *file, t_map *map);
int		get_col_nb(char *line);
void	free_all(char **strs);
void	free_and_null(char *str);
void	load_map(t_map *map, int line_count, int col_count);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:52:05 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/22 16:02:45 by vboulang         ###   ########.fr       */
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

typedef struct s_point
{
	int		x;
	int		z;
	int		y;
	long	color; //check type in MLX
}	t_point;

typedef struct s_map
{
	int		height;
	int		wide;
	char	*filename;
	t_point	**point;
	//t_mlx
}	t_map;

int		main(int argc, char **argv);
void	initialize_map(t_map *map, char *str);

void	get_map_size(char *file, t_map *map);
int		get_col_nb(char *line);
void	load_map(t_map *map, int line_count, int col_count);

void	free_all(char **strs);
void	free_and_null(char *str);
void	free_all_map(t_point **point);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:52:05 by vboulang          #+#    #+#             */
/*   Updated: 2024/02/09 12:59:31 by vboulang         ###   ########.fr       */
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
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	double	isox;
	double	isoy;
	u_int32_t	color; //check type in MLX
}	t_point;

typedef struct s_map
{
	int		height;
	int		width;
	int		window_height;
	int		window_width;
	char	*filename;
	t_point	**point;
	mlx_t	*mlx;
}	t_map;

int		main(int argc, char **argv);
void	initialize_map(t_map *map, char *str);

void	get_map_size(char *file, t_map *map);
int		get_col_nb(char *line);
void	create_map(t_map *map, int line_count, int col_count);

void	free_all(char **strs);
void	free_and_null(char *str);
void	free_all_map(t_point **point);

void	printf_map(t_map *map);

void	close_esc(void *param);
void	all_hooks(t_map *map);

void	isometric_conversion(t_point *point);
uint32_t	ft_htoi_base(const char *str, char *base);
#endif
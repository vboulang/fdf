/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:52:05 by vboulang          #+#    #+#             */
/*   Updated: 2024/02/23 20:23:20 by vboulang         ###   ########.fr       */
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
# define WIDTH 1500
# define HEIGHT 1000

typedef struct s_map	t_map;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	double		isox;
	double		isoy;
	t_map		*map;
	u_int32_t	color;
}	t_point;

typedef struct s_map
{
	int			height;
	int			width;
	int			h_dis;
	int			v_dis;
	float		scale;
	float		zoomf;
	float		scalez;
	char		*filename;
	t_point		**point;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_map;

int			main(int argc, char **argv);
void		initialize_map(t_map *map, char *str);
void		draw(t_map *map);
void		draw_points(t_map *map);
void		fill_background(mlx_image_t *img);

void		get_map_size(char *file, t_map *map);
int			get_col_nb(char *line);
void		create_map(t_map *map, int line_count, int col_count);

void		free_all(char **strs);
void		free_and_null(char *str);
void		free_all_map(t_point **point);

void		printf_map(t_map *map);

void		close_esc(void *param);
void		all_hooks(t_map *map);

void		isometric_conversion(t_point *point);
void		update_point(t_map *map);
void		draw_line(mlx_image_t *img, t_point *point, t_point *next);
void		choose_case(mlx_image_t *img, t_point *point, t_point *next);
uint32_t	ft_htoi_base(const char *str, char *base);
#endif
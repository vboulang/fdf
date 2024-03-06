/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:18:15 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/06 15:28:32 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

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
	int			fd;
	float		scale;
	float		zoomf;
	float		scalez;
	char		*filename;
	t_point		**point;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_map;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	p;
	int	di;
}	t_line;

//Functions in fdf_bonus.c
void		fill_background(mlx_image_t *img);
void		draw_points(t_map *map);
void		draw(t_map *map);
void		mlx_func(t_map *map);
int			main(int argc, char **argv);

//Functions in load_map_bonus.c
t_point		create_point(t_map *map, int i, int j, char **splitted_line);
void		filler(t_map *map);
void		fill_map(t_map *map);
void		create_map(t_map *map, int line_count, int col_count);
void		get_map_size(char *file, t_map *map);

//Functions in math_bonus.c
void		isometric_conversion(t_point *point);
void		update_point(t_map *map);
void		draw_line_low(mlx_image_t *img, t_point *point, t_point *next);
void		draw_line_high(mlx_image_t *img, t_point *point, t_point *next);
void		choose_case(mlx_image_t *img, t_point *point, t_point *next);

//Functions in hooks_bonus.c
void		close_esc(void *param);
void		move(void *param);
void		zoom(void *param);
void		change_z(void *param);
void		recenter(void *param);

//Functions in hook_loop_bonus.c
void		all_hooks(t_map *map);

//Functions in utils_bonus.c
void		set_window_restriction(t_map *map, int line_count, int col_count);
int			get_col_nb(char *line);
u_int32_t	ft_atoi_base(const char *str, char *base);
void		init_line_struct(t_line *line, t_point *point, t_point *next);

//Functions in misc_utils_bonus.c
int			check_map(t_map *map);
void		load_map_error(t_map *map, char **strs);
void		initialize_map(t_map *map, char *str);
void		string_mlx(t_map *map);

//Functions in free_utils_bonus.c
void		free_and_null(char *str);
void		free_all_map(t_point **point);
void		free_all(char **strs);
void		free_map(t_map *map);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:25:51 by vboulang          #+#    #+#             */
/*   Updated: 2024/02/24 17:13:53 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
/* TO IMPLEMENT

u = x*cos(α) + y*cos(α+120°) + z*cos(α-120°)
v = x*sin(α) + y*sin(α+120°) + z*sin(α-120°)

OR

x'=(x-z)/sqrt(2)
y'=(x+2y+z)/sqrt(6)

commencer par mettre en cood et regarder s<il faut deplacer la map pour 
quelle soit centr/e
Aurelia ajoute un offset (deplaceent en x et en y) a ses coordonnees 
isometrique. A voir s'il pourrait y avoir une regle
*/

// void	isometric_conversion(t_point *point)
// {
// 	double	u;
// 	double	v;

// 	u = (point->x * cos(45 * M_PI / 180)) - (point->y * sin(45 * M_PI / 180));
// 	v = (point->x * sin(30 * M_PI / 180) * sin(45 * M_PI / 180))
// 		+ (point->y * cos(30 * M_PI / 180))
// 		+ (point->z * sin(asin(tan(30 * M_PI / 180))) * cos(45));

// 	point->isox = ceil(-u * 15) + WIDTH/2;
// 	point->isoy = ceil(v * 15) + HEIGHT/4;
// }

void	isometric_conversion(t_point *point)
{
	double	u;
	double	v;

	u = (point->x - point->y) * -cos(30 * M_PI / 180);
	v = (point->x + point->y) * sin(30 * M_PI / 180)
		- (point->z * point->map->scalez);
	point->isox = ceil(u * (point->map->scale / point->map->zoomf))
		+ (WIDTH / 2) + point->map->h_dis;
	point->isoy = ceil(v * (point->map->scale / point->map->zoomf))
		+ (HEIGHT / 4) + point->map->v_dis;
}

void	update_point(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			isometric_conversion(&map->point[y][x]);
			x++;
		}
		y++;
	}
}

void	draw_line_low(mlx_image_t *img, t_point *point, t_point *next)
{
	t_line	line;

	init_line_struct(&line, point, next);
	if (line.dy < 0)
	{
		line.di = -1;
		line.dy = -line.dy;
	}
	line.p = (2 * line.dy) - line.dx;
	while (line.x < next->isox)
	{
		if ((uint32_t)line.x < img->width && (uint32_t)line.y < img->height
			&& line.x > 0 && line.y > 0)
			mlx_put_pixel(img, line.x, line.y, point->color);
		if (line.p > 0)
		{
			line.y += line.di;
			line.p += (2 * (line.dy - line.dx));
		}
		else
			line.p += (2 * line.dy);
		line.x += 1;
	}
}

void	draw_line_high(mlx_image_t *img, t_point *point, t_point *next)
{
	t_line	line;

	init_line_struct(&line, point, next);
	if (line.dx < 0)
	{
		line.di = -1;
		line.dx = -line.dx;
	}
	line.p = (2 * line.dx) - line.dy;
	while (line.y < next->isoy)
	{
		if ((uint32_t)line.x < img->width && (uint32_t)line.y < img->height
			&& line.x > 0 && line.y > 0)
			mlx_put_pixel(img, line.x, line.y, point->color);
		if (line.p > 0)
		{
			line.x += line.di;
			line.p += 2 * (line.dx - line.dy);
		}
		else
			line.p += (2 * line.dx);
		line.y += 1;
	}
}

/*
	Bresenham algorithm
*/
void	choose_case(mlx_image_t *img, t_point *point, t_point *next)
{
	if (fabs(next->isoy - point->isoy) < fabs(next->isox - point->isox))
	{
		if (point->isox - next->isox > 0)
			draw_line_low(img, next, point);
		else
			draw_line_low(img, point, next);
	}
	else
	{
		if (point->isoy - next->isoy > 0)
			draw_line_high(img, next, point);
		else
			draw_line_high(img, point, next);
	}
}

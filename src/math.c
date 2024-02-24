/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:25:51 by vboulang          #+#    #+#             */
/*   Updated: 2024/02/23 20:23:04 by vboulang         ###   ########.fr       */
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
	v = (point->x + point->y) * sin(30 * M_PI / 180) - (point->z * point->map->scalez);
	point->isox = ceil(u * (point->map->scale/point->map->zoomf)) + (WIDTH / 2) + point->map->h_dis;
	point->isoy = ceil(v * (point->map->scale/point->map->zoomf)) + (HEIGHT / 4) + point->map->v_dis;
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
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	p;
	int	yi;

	dx = next->isox - point->isox;
	dy = next->isoy - point->isoy;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	p = (2 * dy) - dx;
	x = point->isox;
	y = point->isoy;
	while (x < next->isox)
	{
		if ((uint32_t)x < img->width && (uint32_t)y < img->height
			&& x > 0 && y > 0)
			mlx_put_pixel(img, x, y, point->color);
		if (p > 0)
		{
			y += yi;
			p += (2 * (dy - dx));
		}
		else
			p += (2 * dy);
		x += 1;
	}
}

void	draw_line_high(mlx_image_t *img, t_point *point, t_point *next)
{
	int	dx;
	int	dy;
	int	xi;
	int	x;
	int	y;
	int	p;

	dx = next->isox - point->isox;
	dy = next->isoy - point->isoy;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	p = (2 * dx) - dy;
	x = point->isox;
	y = point->isoy;
	while (y < next->isoy)
	{
		if ((uint32_t)x < img->width && (uint32_t)y < img->height
			&& x > 0 && y > 0)
			mlx_put_pixel(img, x, y, point->color);
		if (p > 0)
		{
			x += xi;
			p += 2 * (dx - dy);
		}
		else
			p += (2 * dx);
		y += 1;
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

static int	get_n(char c, char *base)
{
	int	i;

	i = 10;
	if (ft_isdigit(c))
		return (ft_atoi(&c));
	else
	{
		while (base[i])
		{
			if (ft_tolower(base[i]) == c || ft_toupper(base[i]) == c)
				return (i);
			i++;
		}
	}
	return (-1);
}

/*
To convert hexadecimal in any base. Hexadecimal has to start with 0x.

Careful as no protection is implemented in get_n if the 
character isn't in the base characters.
Works even if base is in a different case (for FDF source maps purposes)
*/
uint32_t	ft_htoi_base(const char *str, char *base)
{
	int			i;
	uint32_t	result;
	int			base_length;
	int			len;
	double		multiple;

	base_length = ft_strlen(base);
	len = ft_strlen(str) - 2;
	result = 0;
	i = 2;
	if (!str)
		return (0);
	while (str[i])
	{
		multiple = pow(base_length, len - 1);
		result += (get_n(str[i], base)) * multiple;
		i++;
		len--;
	}
	return (result);
}

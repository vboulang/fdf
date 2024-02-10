/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:25:51 by vboulang          #+#    #+#             */
/*   Updated: 2024/02/10 15:47:45 by vboulang         ###   ########.fr       */
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
	
// 	point->isox = ceil(-u * 15) + point->map->window_width/2;
// 	point->isoy = ceil(v * 15) + point->map->window_height/4;
// }

void	isometric_conversion(t_point *point)
{
	double	u;
	double	v;

	u = (point->x  - point->y) * -cos(30 * M_PI / 180);
	v = (point->x + point->y) * sin(30 * M_PI / 180) - (point->z);
	point->isox = ceil(u * 45) + point->map->window_width/2;
	point->isoy = ceil(v * 45) + point->map->window_height/4;
}

/*
	Bresenham algorithm
*/
int	choose_case(int dx, int dy)
{
	return (0)
}

void	draw_line(mlx_image_t *img, t_point *point, t_point *next)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	p;


	dx = next->isox - point->isox;
	dy = next->isoy - point->isoy;
	p = 2 * dy - dx;
	if (dx > 0)
	{
		x = point->isox;
		y = point->isoy;
		while(x < next->isox)
		{
			if(x < point->map->window_width && y < point->map->window_height && x > 0 && y > 0)
				mlx_put_pixel(img, x, y, point->color);
			if (p >=0)
			{
				y +=1;
				p += 2 * dy - 2 * dx;
			}
			else
				p += 2 * dy;
			x += 1;
		}
	}
	else
	{
		x = next->isox;
		y = next->isoy;
		while(x < point->isox)
		{
			if(x < point->map->window_width && y < point->map->window_height && x > 0 && y > 0)
				mlx_put_pixel(img, x, y, next->color);
			if (p >=0)
			{
				y -=1;
				p += 2 * dy - 2 * dx;
			}
			else
				p += 2 * dy;
			x += 1;
		}
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

Careful as no protection is implemented in get_n if the character isn't in the base characters.
Works even if base is in a different case (for FDF source maps purposes)
*/
uint32_t	ft_htoi_base(const char *str, char *base)
{
	int	i;
	uint32_t	result;
	int	base_length;
	int	len;
	double	multiple;

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

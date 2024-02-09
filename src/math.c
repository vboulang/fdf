/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:25:51 by vboulang          #+#    #+#             */
/*   Updated: 2024/02/09 17:26:19 by vboulang         ###   ########.fr       */
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
	
// 	point->isox = ceil(u);
// 	point->isoy = ceil(v);
// }


void	isometric_conversion(t_point *point)
{
	double	u;
	double	v;

	u = (point->x  - point->y) * cos(30 * M_PI / 180);
	//u = (point->x  - point->y) * (sqrt(2) /2);
	v = (point->x + point->y) * sin(30 * M_PI / 180) - (point->z);
	//v = (((point->x + point->z)  * (sqrt(6) /6)) + (point->y * cos(sqrt(3)/3)));

	point->isox = ceil(-u * 10); //why minus
	point->isoy = ceil(v * 10);
}

// double	bresenham(int x1, int x2, int y1, int y2)
// {
	
// }
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
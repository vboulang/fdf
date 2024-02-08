/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:25:51 by vboulang          #+#    #+#             */
/*   Updated: 2024/02/08 16:26:26 by vboulang         ###   ########.fr       */
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

void	isometric_conversion(t_point *point)
{
	double	u;
	double	v;

	u = (point->x * cos(45 * M_PI / 180)) - (point->y * sin(45 * M_PI / 180));
	v = (point->x * sin(30 * M_PI / 180) * sin(45 * M_PI / 180))
		+ (point->y * cos(30 * M_PI / 180))
		+ (point->z * sin(asin(tan(30 * M_PI / 180))) * cos(45));
	point->isox = ceil(u);
	point->isoy = ceil(v);
}

// double	bresenham(void)
// {

// }

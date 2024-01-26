/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:25:51 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/26 14:48:52 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/fdf.h"
/* TO IMPLEMENT

u = x*cos(α) + y*cos(α+120°) + z*cos(α-120°)
v = x*sin(α) + y*sin(α+120°) + z*sin(α-120°)

OR

x'=(x-z)/sqrt(2)
y'=(x+2y+z)/sqrt(6)

*/

double	isometric_conversion(t_point point)
{
	double	u;
	double	v;

	u = (point.x * cos(STARTING_ANGLE)) + () + ();
}

// double	bresenham(void)
// {
	
// }

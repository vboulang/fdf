/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:45:33 by vboulang          #+#    #+#             */
/*   Updated: 2024/02/24 16:48:14 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_and_null(char *str)
{
	free(str);
	str = NULL;
}

void	free_all_map(t_point **point)
{
	int	i;

	i = 0;
	while (point[i])
		i++;
	i--;
	while (i >= 0)
	{
		free(point[i]);
		point[i] = NULL;
		i--;
	}
	free(point);
	point = NULL;
}

void	free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	i--;
	while (i >= 0)
	{
		free_and_null(strs[i]);
		i--;
	}
	free(strs);
	strs = NULL;
}

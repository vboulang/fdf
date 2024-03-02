/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:46:45 by vboulang          #+#    #+#             */
/*   Updated: 2024/03/02 12:48:51 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_window_restriction(t_map *map, int line_count, int col_count)
{
	float	scalex;
	float	scaley;

	scalex = (float)WIDTH / col_count;
	scaley = (float)HEIGHT / line_count;
	if (scalex > scaley)
		map->scale = scaley;
	else
		map->scale = scalex;
	map->height = line_count;
	map->width = col_count;
}

int	get_col_nb(char *line)
{
	char	**splitted_line;
	int		i;

	splitted_line = ft_split(line, ' ');
	i = 0;
	while (splitted_line[i])
		i++;
	free_all(splitted_line);
	return (i);
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
uint32_t	ft_atoi_base(const char *str, char *base)
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

void	init_line_struct(t_line *line, t_point *point, t_point *next)
{
	line->dx = next->isox - point->isox;
	line->dy = next->isoy - point->isoy;
	line->di = 1;
	line->x = point->isox;
	line->y = point->isoy;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:15:56 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/20 14:14:24 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*b;

	i = 0;
	b = s;
	if (!b)
		return ;
	if (n > 0)
	{
		while (i < n)
		{
			b[i] = '\0';
			i++;
		}
	}
}

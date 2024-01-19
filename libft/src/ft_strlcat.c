/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:39:05 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/19 16:03:06 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	j = 0;
	i = 0;
	if (!dst || !src)
		return (0);
	len = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src) + dstsize);
	while (dst[i])
		i++;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (len <= dstsize)
		dst[i] = '\0';
	else
		return (ft_strlen(src) + dstsize);
	return (len + ft_strlen(src));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:39:05 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/20 14:16:56 by vboulang         ###   ########.fr       */
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
/*
#include <string.h>
#include <stdio.h>

int main()
{
	char str[60] = "Hello";
	char str2[7] = "Tortue";
	char str3[60] = "Hello";
	char str4[7] = "Tortue";
	printf("%lu %u %s %s\n", strlcat(str, str2, 1), 
	ft_strlcat(str3, str4, 1), str, str3);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:22:05 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/20 14:15:29 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*tmpdst;
	char			*tmpsrc;

	i = 0;
	if (!dst || !src)
		return (dst);
	tmpdst = (char *)dst;
	tmpsrc = (char *)src;
	while (i < n)
	{
		tmpdst[i] = tmpsrc[i];
		i++;
	}
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>

int main()
{
	//char dst[10] = "ABcdEFtgy";
	//char dst2[10] = "ABcdEFtgy";
	char src[10] = "Turtle !!";
	//char src[1] = "";
	//char dst[1] = "";
	//char dst2[1] = "";
	//unsigned int len = 9;
	
	//printf("len: %d\n%s\n%s\n", len, memcpy(dst, src, len), 
	//ft_memcpy(dst2, src, len));
}
*/

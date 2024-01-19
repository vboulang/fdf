/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:15:34 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/20 14:15:32 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void	*dst, const void *src, size_t len)
{
	char			*tmpdst;
	char			*tmpsrc;

	if (!dst || !src || len == 0)
		return (dst);
	tmpdst = (char *)dst;
	tmpsrc = (char *)src;
	if (src > dst)
	{
		while (len--)
			*tmpdst++ = *tmpsrc++;
	}
	else
	{
		tmpdst += len - 1;
		tmpsrc += len - 1;
		while (len--)
			*tmpdst-- = *tmpsrc--;
	}
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>

int main()
{
	char str[10] = "helloloki";
	char str2[4] = "Bor";
	char str3[10];
	char str4[4];

	strcpy(str3, str);
	strcpy(str4, str2);

	printf("%s\n%s\n", memmove(str, str2, 3), 
	ft_memmove(str3, str4, 3));
	
	char str5[10] = "helloloki";
	char str6[4] = "Bor";
	char str7[10];
	char str8[4];

	strcpy(str7, str5);
	strcpy(str8, str6);

	printf("%s\n%s\n", memmove(str6, str5, 3), 
	ft_memmove(str8, str7, 3));
	
}*/

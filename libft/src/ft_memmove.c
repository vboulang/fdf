/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:15:34 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/19 16:04:15 by vboulang         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:24:54 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/16 16:55:49 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!haystack || !needle)
		return (NULL);
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i] && needle[j]
				&& haystack[i] == needle[j] && i < n)
			{
				if (!needle[j + 1])
					return ((char *)haystack + (i - j));
				i++;
				j++;
			}
		}
		i = i - j + 1;
	}
	return (NULL);
}

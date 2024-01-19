/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:00:41 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/20 14:16:48 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*str;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	str = malloc(len + 1);
	if (str == 0)
		return (0);
	str = ft_strcpy(str, src);
	return (str);
}

/*
#include <stdio.h>

int	main()
{
	char str[10] = "Hello!";
	char *str2 = NULL;

	printf("Before: %s\n", str2);
	str2 = ft_strdup(str);
	printf("After: %s\n", str2);
}*/

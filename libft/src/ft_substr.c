/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:42:57 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/20 14:17:30 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_to_alloc;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		return (ft_strdup((char *)s + start));
	len_to_alloc = ft_strlen(s + start);
	if (len_to_alloc > len)
		len_to_alloc = len;
	sub = malloc((len_to_alloc + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
/*
#include <stdio.h>

int main()
{
	char str[20] = "Je suis une tortue.";
	printf("%s\n", ft_substr("", 0, 0));
	printf("%s\n", ft_substr(str, 3, 4));
	printf("%s\n", ft_substr(str, 8, 11));
	printf("%s\n", ft_substr(str, 12, 7));
}*/

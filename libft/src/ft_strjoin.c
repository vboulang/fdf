/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:22:21 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/20 14:16:52 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*newstr;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(len * sizeof(char) + 1);
	if (!newstr)
		return (NULL);
	newstr[len] = '\0';
	i = 0;
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		newstr[i++] = s2[j++];
	return (newstr);
}
/*
#include <stdio.h>
int main()
{
	char str1[1] = "";
	char str2[1] = "";
	printf("%s\n", ft_strjoin(str1, str2));
}*/

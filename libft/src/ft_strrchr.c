/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:26:31 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/20 14:17:23 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*ret;

	if (!s)
		return (NULL);
	ret = NULL;
	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			ret = str;
		str++;
	}
	if (*str == (char)c)
		return (str);
	return (ret);
}
/*
#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
	int c = 'a';
	if(ac == 2)
		printf("%s\n%s\n", strrchr(av[1], c), ft_strrchr(av[1], c));
}*/

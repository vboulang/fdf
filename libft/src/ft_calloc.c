/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:33:48 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/20 14:14:27 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(count * size);
	if (!s)
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}
/*
#include <stdio.h>

int main()
{
	int *a;
	int *b;
	char *c;
	char *d;

	a = calloc(8, sizeof(int));
	b = ft_calloc(8, sizeof(int));
	c = calloc(16, sizeof(char));
	d = ft_calloc(16, sizeof(char));

	printf("%d %d", ft_memcmp(a, b, 4), ft_memcmp(c, d, 16));
	free(a);
	free(b);
	free(c);
	free(d);
}*/

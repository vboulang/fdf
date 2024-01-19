/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:58:31 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/20 14:15:36 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*b2;

	if (!b)
		return (NULL);
	b2 = b;
	i = 0;
	while (i < len)
	{
		b2[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
#include <string.h>

int main()
{
	char str[50]="Je suis une tortue qui mange une salade";
	char str2[50]="Je suis une tortue qui mange une salade";
	int len = 10;
	int c = 'h';

	printf("%s\n%s\n", memset(str, c, len), ft_memset(str2, c, len));
}*/

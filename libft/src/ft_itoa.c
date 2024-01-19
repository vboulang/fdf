/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:24:10 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/19 16:05:22 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_nb_size(int n)
{
	int	len;
	int	nbr;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	nbr = n;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		nbr;
	char	*str;

	len = ft_nb_size(n);
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	nbr = n;
	if (nbr == -2147483648)
	{
		str[--len] = ((nbr % 10) * -1) + 48;
		nbr /= 10;
	}
	if (nbr < 0)
		nbr *= -1;
	while (len-- > 0)
	{
		str[len] = (nbr % 10) + 48;
		nbr /= 10;
	}
	if (n < 0)
		str[++len] = '-';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:29:08 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/20 14:15:46 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	reste;
	int	division;

	if (n < 0)
	{
		write(fd, "-", 1);
		reste = n % 10 * -1;
		division = n / 10 * -1;
		if (n == -2147483648)
			n = n +1 * -1;
		else
			n = n * -1;
	}
	else
	{
		reste = n % 10;
		division = n / 10;
	}
	if (n > 9)
		ft_putnbr_fd(division, fd);
	reste = reste + 48;
	write(fd, &reste, 1);
}
/*
int main()
{
	ft_putnbr_fd(123456, 1);
	ft_putnbr_fd(-654321, 2);
}*/

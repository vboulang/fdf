/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:16:21 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/20 14:17:26 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_check_set(char const *s1, char const *set, int len_s1, int inc)
{
	int	i;
	int	j;
	int	to_remove;

	to_remove = 1;
	if (inc == -1)
		i = len_s1 - 1;
	else
		i = 0;
	while (s1[i] && to_remove)
	{
		to_remove = 0;
		j = 0;
		while (set[j] && !to_remove)
		{
			if (set[j] == s1[i])
				to_remove = 1;
			j++;
		}
		i += inc;
	}
	i -= inc;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len_s1;
	int		start;
	int		last;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	len_s1 = ft_strlen(s1);
	start = ft_check_set(s1, set, len_s1, 1);
	if (start == len_s1 - 1)
		return (ft_strdup(""));
	last = ft_check_set(s1, set, len_s1, -1);
	trimmed = malloc((last - start + 1) * sizeof(char) + 1);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, last - start + 2);
	return (trimmed);
}
/*
#include <stdio.h>
int	main()
{
	char s1[20] = "gggjjjgjjgjgjgj";
	char	set[3] = "gj";
	printf("%s\n", ft_strtrim(s1, set));
}*/

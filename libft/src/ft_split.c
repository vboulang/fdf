/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:02:33 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/20 14:16:32 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	count_word(char const *s, char c)
{
	int	nb_word;
	int	i;
	int	in_word;

	i = 0;
	in_word = 0;
	nb_word = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			nb_word += 1;
			in_word = 1;
		}
		else if (s[i] == c && in_word == 1)
			in_word = 0;
		i++;
	}
	return (nb_word);
}

static int	ft_strlen_word(const char *s, char c, int i)
{
	int	len;
	int	in_word;

	len = 0;
	in_word = 0;
	while (s[i] && in_word < 2)
	{
		if (s[i] != c && in_word == 0)
		{
			len++;
			in_word = 1;
		}
		else if (s[i] == c && in_word == 1)
			in_word++;
		else if (s[i] != c && in_word == 1)
			len++;
		i++;
	}
	return (len);
}

static char	**ft_splitting(char **strs, const char *s, char c)
{
	int	i;
	int	word;
	int	len;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = ft_strlen_word(s, c, i);
			strs[word] = ft_calloc(len + 1, sizeof(char));
			if (!strs[word])
			{
				while (word--)
					free(strs[word]);
				free(strs);
				return (NULL);
			}
			ft_strlcpy(strs[word], s + i, len + 1);
			i += ft_strlen(strs[word++]) - 1;
		}
		i++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**strs;

	if (!s)
		return (NULL);
	word_count = count_word(s, c);
	strs = ft_calloc((word_count + 1), sizeof(char *));
	if (!strs)
		return (NULL);
	strs = ft_splitting(strs, s, c);
	if (!strs)
		return (NULL);
	return (strs);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**strs;
//	char	str1[42] = "Je suis une tortue qui mange des ramens!!";
//	char	str2[42] = "                                         ";
//	char	str3[42] = "   Je suis     une    tortue des ramens  ";
	char	str4[42] = "\0                                  tortue";
	char	c = '\0';
	int		i = 0;

	strs = ft_split(str4, c);
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
	if(strs[i] == NULL)
		printf("%s\n", strs[i]);
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}*/

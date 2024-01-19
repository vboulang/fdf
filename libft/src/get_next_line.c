/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:05:22 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/05 14:27:31 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*check_size_read(int size_read, char **new_string)
{
	if (size_read == 0)
	{
		if (*new_string[0] == '\0')
			return (free(*new_string), NULL);
		else
			return (*new_string);
	}
	else
	{
		if (*new_string)
			free(*new_string);
		return (NULL);
	}
}

int	read_one_line(char **check, int fd, char **new_string, char *buff)
{
	int	size_read;

	size_read = 1;
	while (!(*check) && size_read != 0)
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		size_read = read(fd, buff, BUFFER_SIZE);
		if (size_read >= 0)
		{
			*new_string = ft_strjoin_gnl(*new_string, buff);
			if (!new_string)
				return (-1);
			*check = ft_strchr(*new_string, '\n');
		}
		else
			return (-1);
	}
	return (size_read);
}

char	*ft_to_return(char *str, char *reste)
{
	char	*to_return;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str) - ft_strlen(reste);
	to_return = malloc((len + 1) * sizeof(char));
	if (!to_return)
		return (free(str), NULL);
	to_return[len] = '\0';
	while (i < len)
	{
		to_return[i] = str[i];
		i++;
	}
	free(str);
	return (to_return);
}

char	*initialize(char *buff)
{
	char		*new_string;

	new_string = malloc(1 * sizeof(char));
	if (!new_string)
		return (NULL);
	new_string[0] = '\0';
	new_string = ft_strjoin_gnl(new_string, buff);
	if (!new_string)
		return (NULL);
	return (new_string);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			size_read;
	char		*new_string;
	char		*check;
	char		*to_return;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		return (NULL);
	}
	new_string = initialize(buff);
	if (!new_string)
		return (NULL);
	check = ft_strchr(new_string, '\n');
	size_read = read_one_line(&check, fd, &new_string, buff);
	if (size_read <= 0)
		return (check_size_read(size_read, &new_string));
	ft_strlcpy(buff, ++check, BUFFER_SIZE + 1);
	to_return = ft_to_return(new_string, check);
	if (!to_return)
		return (NULL);
	return (to_return);
}

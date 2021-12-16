/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 12:33:40 by dsaat         #+#    #+#                 */
/*   Updated: 2021/12/13 12:33:41 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	if (!s)
		return (NULL);
	index = ft_strlen((char *)s);
	while (index >= 0)
	{
		if (*(s + index) == (char)c)
			return ((char *)s + index);
		index--;
	}
	return (NULL);
}

static char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = (void *) malloc(count * size);
	if (!ptr)
		return (NULL);
	while (size > 0)
	{
		ptr[size - 1] = '\0';
		size--;
	}
	return (ptr);
}

char	*ft_strjoin(char *save, char *buff)
{
	size_t	i;
	char	*str;

	if (!save)
		save = (char *)ft_calloc(1, sizeof(char));
	if (!save || !buff)
		return (NULL);
	str = ft_calloc(1, sizeof(char) * (ft_strlen(save) + ft_strlen(buff) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (save[i] != '\0')
	{
		str[i] = save[i];
		i++;
	}
	while (*buff != '\0')
	{
		str[i] = *buff;
		i++;
		buff++;
	}
	free(save);
	return (str);
}

char	*ft_substr(char *save, unsigned int start, size_t len, int extra)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)ft_calloc(1, sizeof(char) * (len + extra));
	if (!str)
		return (NULL);
	while (save[start + i] && i < len)
	{
		str[i] = save[start + i];
		i++;
	}
	if (save[start + i] == '\n')
	{
		str[i] = save[start + i];
		i++;
	}
	return (str);
}

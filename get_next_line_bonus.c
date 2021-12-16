/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 12:33:30 by dsaat         #+#    #+#                 */
/*   Updated: 2021/12/13 12:33:31 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_newsave(char *save)
{
	char	*newsave;
	int		i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	newsave = ft_substr(save, i + 1, ft_strlen(save) - (i + 1), 1);
	free(save);
	return (newsave);
}

static char	*ft_getline(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_substr(save, 0, i, 2);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save[1025];
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			b_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	b_read = 1;
	while (!ft_strrchr(save[fd], '\n') && b_read != 0)
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read < 0)
			return (NULL);
		buff[b_read] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
		if (!save[fd])
			return (NULL);
	}
	line = ft_getline(save[fd]);
	save[fd] = ft_newsave(save[fd]);
	return (line);
}

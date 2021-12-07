#include "get_next_line_bonus.h"

// char	*ft_read(char *save, fd)
// {

// }

char	*ft_newsave(char *save)
{
	char	*newsave;
	int 	i;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	newsave = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!newsave)
	{
		free(save);
		return (NULL);
	}
	i++;
	j = 0;
	while (save[i])
	{
		newsave[j] = save[i];
		i++;
		j++;
	}
	newsave[j] = '\0';
	free(save);
	return (newsave);

}

char	*ft_getline(char *save)
{
	char	*line;
	int		i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
	{
		free(save);
		return (NULL);
	}
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
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
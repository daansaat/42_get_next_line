#include "libft.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 10

typedef struct txt_list
{
	char				*txt;
	// int 				fd;
	// struct s_list	*next;
}						t_txt_list;

char	*get_next_line(int fd)
{
	static t_txt_list	*data;
	char				buff[BUFFER_SIZE + 1];
	char				*line;
	int					len;
	int					i;

	puts("hello\n");
	len = ft_strlen(data->txt);
	printf("%d", len);
	while (read(fd, buff, BUFFER_SIZE))
	{
		buff[BUFFER_SIZE] = '\0';
		puts(buff);
		data->txt = strncat(data->txt, buff, len + BUFFER_SIZE);
		puts(data->txt);
	}
	line = ft_strdup(data->txt);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			data->txt = ft_substr(data->txt, i, ft_strlen(line) - i);
			return (ft_substr(line, 0, i));
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
}

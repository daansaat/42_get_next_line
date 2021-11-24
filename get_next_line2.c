#include "libft.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 50

typedef struct txt_list
{
	char				*txt;
	// int 				fd;
	// struct s_list	*next;
}						t_txt_list;

char	*get_next_line(int fd)
{
	static char	*txt = "";
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			b_read;
	int			i;

	b_read = read(fd, buff, BUFFER_SIZE);
	buff[b_read] = '\0';
	txt = ft_strjoin(txt, buff);
	i = 0;
	line = ft_strdup(txt);
	while ((txt[i]) || (txt[i] == '\0' && b_read == 0 && ft_strlen(txt) > 0))
	{
		if ((txt[i] == '\n')
			|| (txt[i] == '\0' && b_read == 0 && ft_strlen(txt) > 0))
		{
			txt = ft_substr(txt, i + 1, ft_strlen(line) - (i + 1));
			free (line);
			//free(txt);
			return (ft_substr(line, 0, i));
		}
		i++;
	}
	//free(line);
	//free(txt);
	return (0);
}

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	puts(get_next_line(fd));
	puts(get_next_line(fd));
	puts(get_next_line(fd));
	puts(get_next_line(fd));
	puts(get_next_line(fd));
	system("leaks a.out");

}

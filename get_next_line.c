#include "so_long_lib.h"

char	*get_next_line(int fd)
{
	char		*line1;
	static char	*save;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	save = get_read_save(fd, save);
	if (save == NULL)
		return (NULL);
	line1 = get_line(save);
	save = get_rest(save);
	return (line1);
}

char	*get_read_save(int fd, char *save)
{
	char	*buffer;
	int		nbchars;

	buffer = (char *)malloc(sizeof(char) * (1 + 1));
	if (!buffer)
		return (NULL);
	nbchars = 1;
	while ((str_chr(save, '\n') == NULL) && nbchars > 0)
	{
		nbchars = read(fd, buffer, 1);
		if (nbchars == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbchars] = '\0';
		save = str_join(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_line(char *save)
{
	int		x;
	char	*line;

	x = 0;
	if (!save[x])
		return (NULL);
	line = (char *)malloc(sizeof(char) * (len_line(save) + 2));
	if (!line)
		return (NULL);
	while (save[x] != '\0' && save[x] != '\n')
	{
		line[x] = save[x];
		x++;
	}
	if (save[x] == '\n')
	{
		line[x] = '\n';
		x++;
	}
	line[x] = '\0';
	return (line);
}
char	*get_rest(char *save)
{
	int		i;
	int		n;
	char	*rest;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen2(save) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	n = 0;
	while (save[i] != '\0')
		rest[n++] = save[i++];
	rest[n] = '\0';
	free(save);
	return (rest);
}

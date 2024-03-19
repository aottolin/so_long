#include "so_long_lib.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		*save;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	save = NULL;
	if (fd < 0)
		return (NULL);
	line = get_read_save(fd, save);
	return (line);
}

char	*get_read_save(int fd, char *save)
{
	char	*buffer;
	int		nbchars;

	buffer = (char *)malloc(sizeof(char) * (1 + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	nbchars = 1;
	while ((str_chr(save, '\n') == NULL) && nbchars > 0)
	{
		nbchars = read(fd, buffer, 1);
		if (nbchars == -1)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		if (nbchars > 0)
		{
			buffer[nbchars] = '\0';
			save = str_join(save, buffer);
		}
	}
	free(buffer);
	return (save);
}


#include "so_long_lib.h"

char	*str_chr(char *save, int newline)
{
	int	x;

	x = 0;
	if (!save)
		return (NULL);
	if (newline == '\0')
		return ((char *)&save[ft_strlen2(save)]);
	while (save[x] != newline && save[x] != '\0')
		x++;
	if (save[x] == newline)
		return (save);
	return (NULL);
}

char *str_join(char *save, char *buffer)
{
    int len_save = (save != NULL) ? strlen(save) : 0;
    int len_buffer = (buffer != NULL) ? strlen(buffer) : 0;
    int total_length = len_save + len_buffer + 1; // +1 para el carácter nulo
    char *new;

    new = (char *)malloc(total_length * sizeof(char));
    if (new == NULL) {
        // Manejo de error: No se pudo asignar memoria
        return NULL;
    }

    // Copiar la cadena save a new
    if (save != NULL) {
        strcpy(new, save);
    } else {
        new[0] = '\0';
    }

    // Concatenar la cadena buffer a new
    if (buffer != NULL) {
        strcat(new, buffer);
    }

    return new;
}


int	len_line(char *line)
{
	int	len;

	len = 0;
	while (line[len] != '\0' && line[len] != '\n')
		len++;
	return (len);
}



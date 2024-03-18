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

char	*str_join(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen2(s1) + ft_strlen2(s2) + 1));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = 0;
	while (s2[c])
	{
		str[i + c] = s2[c];
		c++;
	}
	str[ft_strlen2(s1) + ft_strlen2(s2)] = '\0';
	//free(s1);
	return (str);
}

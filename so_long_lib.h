# ifndef SO_LONG_LIB_H
# define SO_LONG_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf/ft_printf.h"

typedef struct	d_list
{
	void	*mlx;
	void	*win;
	int		moves;
	int		errors;
	char	*big_line;
	int		height;
	int		width;
	int		consum;
	int		exx;
	int		player;
	int		wall;
	int		space_free;
	int		linecontrol;
}	d_list;

void	*ft_memory(size_t count, size_t size);
int		ft_strlen2(char *str);
void	ft_error(d_list *d, int nb);
int		ft_free(d_list *d);
int		len_line(char *line);
char	*str_join(char *save, char *buffer);
char	*str_chr(char *save, int newline);
char	*get_next_line(int fd);
char	*get_read_save(int fd, char *save);
char	*get_line(char *save);
char	*get_rest(char *save);
char	*str_join(char *save, char *buffer);
void	read_map(char *map, d_list *d);
void	check_extension(char *ext, d_list *d);
void	checkline(d_list *d);
void	check_line_break(char *line, d_list *d);
int		init_data(d_list *d, char *map);
#endif

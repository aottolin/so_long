# ifndef SO_LONG_LIB_H
# define SO_LONG_LIB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"
# include <fcntl.h>

typedef struct	dd_list
{
	void	*mlx;
	void	*win;
	void	*fond;
	int		moves;
	void	*imgexit;
	int		errors;
	char	*content;
	int		height;
	int		width_d;
	int		consum;
	int		exx;
	int		player;
	int		wall;
	int		space_free;
	int		linecontrol;
	int		y;
	int		x;
	void	*poke;
	void	*bush;
	void	*npcstart;
}	d_list;

void	*ft_memory(size_t count, size_t size);

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen2(char *str);
void	ft_error(d_list *d, int nb);
int		ft_free(d_list *d);
int		len_line(char *line);
char	*str_chr(char *save, int newline);
char	*get_next_line(int fd);
char	*get_read_save(int fd, char *save);
char	*get_line(char *save);
char	*get_rest(char *save);
char	*str_join(char *save, char *s2);
void	read_map(char *map, d_list *d);
void	check_extension(char *ext, d_list *d);
void	checkline(d_list *d);
void	check_line_break(char *line, d_list *d);
void	check_first_last_line(d_list *d);
void	check_start_line(d_list *d);
int		init_data(d_list *d, char *map);
void	init_img(d_list *d);
void	calc_xy(char r, int i, d_list *d);
void	print_map(d_list *d);
#endif

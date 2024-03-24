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
	void	*img_fond;
	void	*img_exit;
	void	*img_food;
	void	*img_walls;
	void	*img_player;
	void	*background;
	int		moves;
	int		color;
	int		errors;
	int		height;
	int		width_d;
	int		consum;
	int		exx;
	int		player;
	int		wall;
	int		space_free;
	int		npccontrol;
	int		linecontrol;
	int		y;
	int		x;
	char	*content;
}	d_list;

void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
int		init_data(d_list *d, char *map);
void	init_img(d_list *d);
void	check_extension(char *ext, d_list *d);
int		ft_strlen2(char *str);
void	ft_error(d_list *d, int nb);
int		ft_free(d_list *d);
char	*get_read_save(int fd, char *save);
char	*get_next_line(int fd);
char	*get_line(char *save);
char	*get_rest(char *save);
int		len_line(char *line);
char	*str_chr(char *save, int newline);
char	*str_join(char *save, char *s2);
void	read_map(char *map, d_list *d);
void	checkline(d_list *d);
void	check_line_break(char *line, d_list *d);
void	check_first_last_line(d_list *d);
void	check_start_line(d_list *d);
void	print_map(d_list *d);
void	calcul_y_x(char c, int iter, d_list *d);
void	move_w(d_list *d);
void	move_s(d_list *d);
void	move_a(d_list *d);
void	move_d(d_list *d);
int	key_press(int key, d_list *d);
int	check_exit(d_list *d, char letter);
#endif

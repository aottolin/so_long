/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_lib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aottolin <aottolin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:07:17 by aottolin          #+#    #+#             */
/*   Updated: 2024/03/27 12:07:18 by aottolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_LIB_H
# define SO_LONG_LIB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"
# include <fcntl.h>

typedef struct dt_list
{
	void	*mlx;
	void	*win;
	void	*img_p_left;
	void	*img_p_right;
	void	*img_p_front;
	void	*img_p_back;
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
}	t_list;

void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
int		init_data(t_list *d, char *map);
void	init_img(t_list *d);
void	check_extension(char *ext, t_list *d);
int		ft_strlen2(char *str);
void	ft_error(t_list *d, int nb);
int		ft_free(t_list *d);
char	*get_read_save(int fd, char *save);
char	*get_next_line(int fd);
char	*get_line(char *save);
char	*get_rest(char *save);
int		len_line(char *line);
char	*str_chr(char *save, int newline);
char	*str_join(char *save, char *s2);
void	read_map(char *map, t_list *d);
void	checkline(t_list *d);
void	check_line_break(char *line, t_list *d);
void	check_first_last_line(t_list *d);
void	check_start_line(t_list *d);
void	print_map(t_list *d);
void	calcul_y_x(char c, int iter, t_list *d);
void	move_w(t_list *d);
void	move_s(t_list *d);
void	move_a(t_list *d);
void	move_d(t_list *d);
int		key_press(int key, t_list *d);
int		check_exit(t_list *d, char letter);
void	check_out(t_list *d);
void	ft_init(t_list *d);
#endif

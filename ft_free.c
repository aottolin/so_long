#include "so_long_lib.h"

int	ft_free(d_list *d)
{
	d->errors = 1;
	if (d->big_line)
		free(d->big_line);
	if (d)
		free(d);
	exit(0);
}

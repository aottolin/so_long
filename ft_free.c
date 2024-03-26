#include "so_long_lib.h"

int	ft_free(t_list *d)
{
	d->errors = 1;
	if (d->content)
		free(d->content);
	if (d)
		free(d);
	exit(0);
}

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <stdbool.h>

typedef struct s_elems {
	int		number;
	size_t	index;
	t_elems	*prev;
	t_elems	*next;

}	t_elems;

typedef struct s_stack {
	size_t	len;
	t_elems	*head;
}	t_stack;

#endif
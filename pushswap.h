#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <stdio.h>

typedef struct s_elems {
	int		number;
	bool	store;
	size_t	len;

}	t_elems;

void	terminate(void);
void	solved(t_elems *a);
bool	checkorder(t_elems *a);

void	sa(t_elems *a);
void	sb(t_elems *b);
void	ss(t_elems *a, t_elems *b);
void	pa(t_elems *a, t_elems *b);
void	pb(t_elems *a, t_elems *b);
void	ra(t_elems *a);
void	rb(t_elems *b);
void	rr(t_elems *a, t_elems *b);
void	rra(t_elems *a);
void	rrb(t_elems *a);
void	rrr(t_elems *a, t_elems *b);

void	solve_2(t_elems *a);
void	solve_3(t_elems *a);
void	solver(t_elems *a, t_elems *b);

#endif
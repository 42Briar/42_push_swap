#include "pushswap.h"

void	solve_2(t_elems *a)
{
	if (a[0].number > a[1].number)
		sa(a);
	return ;
}

void	solve_3(t_elems *a)
{
	if (a[0].number > a[1].number && a[1].number > a[2].number)
	{
		sa(a);
		rra(a);
	}
	else if (a[0].number > a[1].number && a[0].number > a[2].number)
		ra(a);
	else if (a[2].number > a[0].number && a[2].number > a[1].number && \
	a[1].number < a[0].number)
		sa(a);
	else if (a[1].number > a[0].number && a[1].number > a[2].number && \
	a[2].number > a[0].number)
	{
		rra(a);
		sa(a);
	}
	else if (a[1].number > a[0].number && a[1].number > a[2].number && \
	a[0].number > a[2].number)
		rra(a);
}

void	solve_4(t_elems *a, t_elems *b)
{
	while (true)
	{
		if (a[0].index == 0)
		{
			pb(a, b);
			break ;
		}	
		rra(a);
	}
	solve_3(a);
	pa(a, b);
}

void	solve_5(t_elems *a, t_elems *b)
{
	while (a[3].store == true)
	{
		if (a[0].index <= 1)
			pb(a, b);
		rra(a);
	}
	solve_3(a);
	pa(a, b);
	if (a[0].index < b[0].index)
	{
		pa(a, b);
		sa(a);
	}
	else
		pa(a, b);
}

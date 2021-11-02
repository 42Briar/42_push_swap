#include "pushswap.h"

void	solve_2(t_elems *a)
{
	if (a[0].number > a[1].number)
		sa(a);
	solved(a);
}

void	solve_3(t_elems *a)
{
	if (a[0].number > a[1].number && a[1].number > a[2].number)
	{
		sa(a);
		rra(a);
		solved(a);
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
	solved(a);
}

void	solver(t_elems *a, t_elems *b)
{
	int	i;
	int	temp[2];

	if (a[1].store == false)
		return ;
	i = 0;
	temp[1] = INT32_MAX;
	while (a[i].store == true)
	{
		if (a[i].number < temp[1])
		{
			temp[1] = a[i].number;
			temp[0] = i;
		}	
		i++;
	}
	if (temp[0] > a[0].len / 2)
	{
		while (a[0].number != temp[1])
			rra(a);
	}
	else
		while (a[0].number != temp[1])
			ra(a);
	pb(a, b);
	solver(a, b);
}

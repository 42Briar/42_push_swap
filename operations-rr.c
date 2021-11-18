#include "pushswap.h"

void	rra(t_elems *a)
{
	size_t	i;
	int		temp;
	int		temp2;

	i = 0;
	write(1, "rra\n", 4);
	while (a[i].store == true && i < a[i].len)
		i++;
	temp = a[i - 1].number;
	temp2 = a[i - 1].index;
	while (i > 0)
	{
		a[i].number = a[i - 1].number;
		a[i].index = a[i - 1].index;
		i--;
	}
	a[0].number = temp;
	a[0].index = temp2;
}

void	rrb(t_elems *a)
{
	size_t	i;
	int		temp;
	int		temp2;

	i = 0;
	write(1, "rrb\n", 4);
	while (a[i].store == true && i < a[i].len)
		i++;
	temp = a[i - 1].number;
	temp2 = a[i - 1].index;
	while (i >= 0)
	{
		a[i].number = a[i - 1].number;
		a[i].index = a[i - 1].index;
		i--;
	}
	a[0].number = temp;
	a[0].index = temp2;
}

void	rrr(t_elems *a, t_elems *b)
{
	write(1, "rrr\n", 4);
	rra(a);
	rrb(b);
}

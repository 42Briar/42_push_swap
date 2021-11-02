#include "pushswap.h"

void	rra(t_elems *a)
{
	int	i;
	int	temp;

	i = 0;
	write(1, "rra\n", 4);
	while (a[i].store == true && i < a[i].len)
		i++;
	temp = a[i - 1].number;
	while (i >= 0)
	{
		a[i].number = a[i - 1].number;
		i--;
	}
	a[0].number = temp;
}

void	rrb(t_elems *b)
{
	int	i;
	int	temp;

	i = 0;
	write(1, "rrb\n", 4);
	while (b[i].store == true && i < b[i].len)
		i++;
	temp = b[i - 1].number;
	while (i >= 0)
	{
		b[i].number = b[i - 1].number;
		i--;
	}
	b[0].number = temp;
}

void	rrr(t_elems *a, t_elems *b)
{
	write(1, "rrr\n", 4);
	rra(a);
	rrb(b);
}

#include "pushswap.h"

void	ra(t_elems *a)
{
	int	i;
	int	temp;
	int	temp2;

	write(1, "ra\n", 3);
	temp = a[0].number;
	temp2 = a[0].index;
	i = 0;
	while (a[i].store != false && i < a[i].len)
	{
		a[i].number = a[i + 1].number;
		a[i].index = a[i + 1].index;
		i++;
	}
	a[i - 1].number = temp;
	a[i - 1].index = temp2;
}

void	rb(t_elems *b)
{
	write(1, "rb\n", 3);
	ra(b);
}

void	rr(t_elems *a, t_elems *b)
{
	write(1, "rr\n", 3);
	ra(a);
	rb(b);
}

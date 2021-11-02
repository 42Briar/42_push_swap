#include "pushswap.h"

void	ra(t_elems *a)
{
	int	i;
	int	temp;

	write(1, "ra\n", 3);
	temp = a[0].number;
	i = 0;
	while (a[i].store != false && i < a[i].len)
	{
		a[i].number = a[i + 1].number;
		i++;
	}
	a[i - 1].number = temp;
}

void	rb(t_elems *b)
{
	int	i;
	int	temp;

	write(1, "rb\n", 3);
	temp = b[0].number;
	i = 0;
	while (b[i].store != false && i < b[i].len)
	{
		b[i].number = b[i + 1].number;
		i++;
	}
	b[i - 1].number = temp;
}

void	rr(t_elems *a, t_elems *b)
{
	write(1, "rr\n", 3);
	ra(a);
	rb(b);
}

#include "pushswap.h"

void	sa(t_elems *a)
{
	int	temp;
	int	temp2;

	write(1, "sa\n", 3);
	if (!a[0].store || !a[1].store)
		return ;
	temp = a[0].number;
	temp2 = a[0].index;
	a[0].number = a[1].number;
	a[0].index = a[1].index;
	a[1].index = temp2;
	a[1].number = temp;
}

void	sb(t_elems *a)
{
	int	temp;
	int	temp2;

	write(1, "sb\n", 3);
	if (!a[0].store || !a[1].store)
		return ;
	temp = a[0].number;
	temp2 = a[0].index;
	a[0].number = a[1].number;
	a[0].index = a[1].index;
	a[1].index = temp2;
	a[1].number = temp;
}

void	ss(t_elems *a, t_elems *b)
{
	write(1, "ss\n", 3);
	sa(a);
	sb(b);
}
